#include"triangle.h"


Triangle::Triangle(glm::vec2 first, glm::vec2 second, glm::vec2 third)
{
	point[0] = first;
	point[1] = second;
	point[2] = third;

	buildTriangle();
	computeDirections();
	computeNormals();
}

void Triangle::buildTriangle()
{

	float Cords[] =
	{
		point[0].x,point[0].y,
		point[1].x,point[1].y,
		point[2].x,point[2].y,


	};

	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Cords), &Cords, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)(0));
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);



}

void Triangle::computeDirections()
{
	dir[0] = point[1] - point[0];
	dir[1] = point[2] - point[1];
	dir[2] = point[0] - point[2];



}

glm::vec2 Triangle::getPointByIndex(int i)
{
	return point[i];

}

glm::vec2  Triangle::getNormalByIndex(int i)
{
	return normal[i];

}

void Triangle::computeNormals()
{

	normal[0] = glm::normalize(glm::vec2(-dir[0].y, dir[0].x));
	normal[1] = glm::normalize(glm::vec2(-dir[1].y, dir[1].x));
	normal[2] = glm::normalize(glm::vec2(-dir[2].y, dir[2].x));


	if (!checkClockwise())
	{
		normal[0] = -normal[0];
		normal[1] = -normal[1];
		normal[2] = -normal[2];
	}



}

void Triangle::printDirections()
{
	for (int i = 0; i < 3; i++)
	{
		std::cout << dir[i].x << " " << dir[i].y << "\n";

	}


}

bool Triangle::checkClockwise()

{

	float area;

	area = glm::determinant(glm::mat3{ 1.0f,1.0f,1.0f,
	   point[0].x,point[1].x,point[2].x,
	   point[0].y,point[1].y,point[2].y, });


	return(area < 0);

}

void Triangle::printNormals()

{
	for (int i = 0; i < 3; i++)
	{
		std::cout << normal[i].x << " " << normal[i].y << "\n";

	}
}

void Triangle:: printPoints()
{
	for (int i = 0; i < 3; i++)
	{
		std::cout << point[i].x << " " << point[i].y << " \n";
	}
}