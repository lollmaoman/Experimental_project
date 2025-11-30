
#include"triangleCollision.h"
#include"ResourceNamespace.h"

float getProjections(glm::vec2 point, glm::vec2 normal)
{

	return(glm::dot(point, glm::normalize(normal)));


}


float getMin(float x, float y, float z)
{


	float min = x;

	if (y < min)
		min = y;

	if (z < min)
		min = z;

	;

	return min;

}

float getMax(float x, float y, float z)
{


	float max = x;

	if (max < y)
		max = y;

	if (max < z)
		max = z;


	return max;


}
bool checkCollisionSingleNormalT1(Triangle& t1, Triangle& t2, int index, int configuration)
{
	float PointsT1[3];
	float PointsT2[3];

	for (int i = 0; i < 3; i++)
	{
		PointsT1[i] = getProjections(t1.point[i], t1.getNormalByIndex(index));

	}

	for (int i = 0; i < 3; i++)
	{
		PointsT2[i] = getProjections(t2.point[i], t1.getNormalByIndex(index));
	}

	float max1 = getMax(PointsT1[0], PointsT1[1], PointsT1[2]);
	float max2 = getMax(PointsT2[0], PointsT2[1], PointsT2[2]);
	float min1 = getMin(PointsT1[0], PointsT1[1], PointsT2[2]);
	float min2 = getMin(PointsT2[0], PointsT2[1], PointsT2[2]);



	if (configuration == 0)
		return(max1 >= min2);

	if (configuration == 1)
		return(max2 >= min1);

}

bool checkCollisionSingleNormalT2(Triangle& t1, Triangle& t2, int index, int configuration)
{
	float PointsT1[3];
	float PointsT2[3];

	for (int i = 0; i < 3; i++)
	{
		PointsT1[i] = getProjections(t1.point[i], t2.getNormalByIndex(index));

	}

	for (int i = 0; i < 3; i++)
	{
		PointsT2[i] = getProjections(t2.point[i], t2.getNormalByIndex(index));
	}

	float max1 = getMax(PointsT1[0], PointsT1[1], PointsT1[2]);
	float max2 = getMax(PointsT2[0], PointsT2[1], PointsT2[2]);
	float min1 = getMin(PointsT1[0], PointsT1[1], PointsT2[2]);
	float min2 = getMin(PointsT2[0], PointsT2[1], PointsT2[2]);



	if (configuration == 0)
		return(max1 >= min2);

	if (configuration == 1)
		return(max2 >= min1);

}

bool performCollisionCheck(Triangle& t1, Triangle& t2)
{
	for (int i = 0; i < 3; i++)
	{
		if (!checkCollisionSingleNormalT1(t1, t2, i, 0))
			return false;
	}

	for (int i = 0; i < 3; i++)
	{
		if (!checkCollisionSingleNormalT1(t1, t2, i, 1))
			return false;
	}

	for (int i = 0; i < 3; i++)
	{
		if (!checkCollisionSingleNormalT2(t1, t2, i, 0))
			return false;
	}

	for (int i = 0; i < 3; i++)
	{
		if (!checkCollisionSingleNormalT2(t1, t2, i, 1))
			return false;
	}

	return true;
}