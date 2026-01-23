#include"triangle.h"
#include<math.h>
Circle::Circle(glm::vec2 centre, float radius)
{

	this->centre = centre;
	this->radius = radius;

	centre_c = centre;

	buildCircle();


}

void Circle::buildCircle()
{

	int n = 128;
    total_vertices = n * 3;
	
	std::vector<glm::vec2>vertices(n);
	const float pi = 3.1415926535f;
	
	for (int i = 0; i < n; i++)
	{
		vertices[i] = glm::vec2(centre.x,centre.y)+glm::vec2(radius*cos((2.0f * i / n)*pi), radius*sin((2.0f *  i / n)*pi));
		
	}

	std::vector<float>quads(total_vertices*2);
	for (int i = 0; i < n; i++)
	{
		int j = i * 6;
	
		quads[j] = centre.x; quads[j + 1] = centre.y;
		quads[j + 2] = vertices[i].x; quads[j + 3] = vertices[i].y;

		if (i != (n - 1))
		{
			quads[j + 4] = vertices[i + 1].x; quads[j + 5] = vertices[i + 1].y;
		}

		else
		{
			quads[j + 4] = vertices[0].x; quads[j + 5] = vertices[0].y;
		}


	}
	


	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, quads.size()*sizeof(float),&quads[0], GL_STATIC_DRAW);


	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)(0));
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
}

void Circle::printRadius()
{
	std::cout << radius << "\n";

}

void Circle::printCentre()
{
	std::cout << centre.x << " X " << centre.y << "Y \n";

}
Triangle::Triangle(glm::vec2 first, glm::vec2 second, glm::vec2 third)
{
	point[0] = first;
	point[1] = second;
	point[2] = third;

	point_c[0] = first;
	point_c[1] = second;
	point_c[2] = third;

	buildTriangle();
	computeDirections();
	computeNormals();
}

void Triangle::buildTriangle()
{

	float Cords[] =
	{
		point_c[0].x,point_c[0].y,
		point_c[1].x,point_c[1].y,
		point_c[2].x,point_c[2].y,


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
	dir[1] =point[2] - point[1];
	dir[2] = point[0] - point[2];



}

glm::vec2 Triangle::getPointByIndex(int i)
{
	return point_c[i];

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


Box::Box(glm::vec2 pointA, glm::vec2 pointB, glm::vec2 pointC, glm::vec2 pointD)
{
	points[0] = pointA;
	points[1] = pointB;
	points[2] = pointC;
	points[3] = pointD;

	for (int i=0;i<4;i++)
	{
		points_c[i] = points[i];
	}
	
	buildBox();
	computeDirections();
	computeNormals();

}

void Box:: buildBox()
{
	 float cords[] {
	
		points_c[0].x,points_c[0].y,
	    points_c[1].x,points_c[1].y,
		points_c[3].x,points_c[3].y,
		points_c[3].x,points_c[3].y,
		points_c[2].x,points_c[2].y,
		points_c[1].x,points_c[1].y,


	};

	 for (int i = 0; i < 12; i++)
	 {
		 Cords[i] = cords[i];
	 }

	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(cords), &cords, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)(0));
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

}
glm::vec2 Box::centralAxis()
{
	glm::vec2 centre = glm::vec2(0.0f);
	for (int i = 0; i < 4; i++)
	{
		centre.x += points[i].x;
		centre.y += points[i].y;

	}

	centre.x /= 4.0f;
	centre.y /= 4.0f;

	return centre;
}
void Box::updateBox()
{

	float cords[]{

		points_c[0].x,points_c[0].y,
		points_c[1].x,points_c[1].y,
		points_c[3].x,points_c[3].y,
		points_c[3].x,points_c[3].y,
		points_c[2].x,points_c[2].y,
		points_c[1].x,points_c[1].y,


	};

	for (int i = 0; i < 4; i++)
	{

		points[i] = points_c[i];
	}
	

	glm::vec2 centre = centralAxis();

	
	for (int i = 0; i < 4; i++)
	{
		points_c[i] -= centre;
	}


	  
	for (int i = 0; i < 4; i++)
	{
		points_c[i] *= scale;
	}

	for (int i = 0; i < 4; i++)
		points_c[i] += centre;

		

	
	
	
		
	
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(cords), cords, GL_DYNAMIC_DRAW);

}

void Box::computeDirections()
{
	dir[0] = points[1] - points[0];
	dir[1] = points[2] - points[1];
	dir[2] = points[3] - points[2];
	dir[3] = points[0] - points[3];

}


void Box::computeNormals()
{
	normals[0] = glm::vec2(-dir[0].y, dir[0].x);
	normals[1] = glm::vec2(-dir[1].y, dir[1].x);
	normals[2] = glm::vec2(-dir[2].y, dir[2].x);
	normals[3] = glm::vec2(-dir[3].y, dir[3].x);



}

void Box::printNormals()
{
	for (int i = 0; i < 4; i++)
	{
		std::cout << "normal " << i << " = " << normals[i].x << " " << normals[i].y << "\n";

	}

}


void Box::printDirections()
{
	for (int i = 0; i < 4; i++)
	{
		std::cout << "direction " << i << " = " << dir[i].x << " " << dir[i].y << "\n";

	}

}

void Box::printPoints()
{

	for (int i = 0; i < 4; i++)
	{
		std::cout << "point " << i << " = " << points_c[i].x << " " << points_c[i].y << "\n";

	}
}