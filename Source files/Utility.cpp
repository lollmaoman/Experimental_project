#include"Utility.h"

namespace Utility
{

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

	float getMinV(std::vector<float>& projections)
	{
		float min = projections[0];

		for (float f : projections)
		{
			if (min > f)
				min = f;

		}
		return min;

	}

	float getMaxV(std::vector<float>& projections)
	{
		float max = projections[0];

		for (float f : projections)
		{
			if (max < f)
				max = f;

		}
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
		float min1 = getMin(PointsT1[0], PointsT1[1], PointsT1[2]);
		float min2 = getMin(PointsT2[0], PointsT2[1], PointsT2[2]);



		if (configuration == 0)
			return(max1 >= min2);

		if (configuration == 1)
			return(max2 >= min1);

		return true;
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
		float min1 = getMin(PointsT1[0], PointsT1[1], PointsT1[2]);
		float min2 = getMin(PointsT2[0], PointsT2[1], PointsT2[2]);



		if (configuration == 0)
			return(max1 >= min2);

		if (configuration == 1)
			return(max2 >= min1);

		return true;
	}

	bool collisionPassTriangle(Triangle& t1, Triangle& t2)
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

	bool checkCollisionSingleNormalB1(Box& b1, Box& b2, int index, bool b1First)
	{
		std::vector<float>pointsb1(4);
		std::vector<float>pointsb2(4);

		for (int i = 0; i < 4; i++)
		{
			pointsb1[i] = getProjections(b1.points_c[i], b1.normals[index]);
			pointsb2[i] = getProjections(b2.points_c[i], b1.normals[index]);

		}

		float min1 = getMinV(pointsb1);
		float max1 = getMaxV(pointsb1);

        float min2 = getMinV(pointsb2);
		float max2 = getMaxV(pointsb2);

		if (b1First)
		{
			return (max1 >= min2);

		}

		else
		{
			return (max2 >= min1);

		}


	}

	bool checkCollisionSingleNormalB2(Box& b1, Box& b2, int index, bool b1First)
	{
		std::vector<float>pointsb1(4);
		std::vector<float>pointsb2(4);

		for (int i = 0; i < 4; i++)
		{
			pointsb1[i] = getProjections(b1.points_c[i], b2.normals[index]);
			pointsb2[i] = getProjections(b2.points_c[i], b2.normals[index]);

		}

		float min1 = getMinV(pointsb1);
		float max1 = getMaxV(pointsb1);

		float min2 = getMinV(pointsb2);
		float max2 = getMaxV(pointsb2);

		if (b1First)
		{
			return (max1 >= min2);

		}

		else
		{
			return (max2 >= min1);

		}


	}
	bool collisionPassBox(Box& box1, Box& box2)
	{

		for (int i = 0; i < 4; i++)
		{
			if (!checkCollisionSingleNormalB1(box1, box2, i, true))
				return false;

		}

		for (int i = 0; i < 4; i++)
		{
			if (!checkCollisionSingleNormalB1(box1, box2, i, false))
				return false;

		}

		for (int i = 0; i < 4; i++)
		{
			if (!checkCollisionSingleNormalB2(box1, box2, i, true))
				return false;

		}

		for (int i = 0; i < 4; i++)
		{
			if (!checkCollisionSingleNormalB2(box1, box2, i, false))
				return false;

		}
		

		return true;
	}
	
	float clamp(float centre, float left, float right)
	{
		

		if (right >= left)
		{

			if (centre >= right)
				return right;
			
			if (centre <= left)
				return left;

			return centre;
		}

		else
		{
			if (centre >= left)
				return left;

			if (centre <= right)
				return right;

			return centre;
		}

	}

	float getNearestDist(glm::vec2 centre,glm::vec2 closestPoint)
	{
		
		float dx = centre.x - closestPoint.x;
		float dy = centre.y - closestPoint.y;

	

		return (dx * dx + dy * dy);


	}

	bool circleBoxCollisionPass(Circle& circle, Box& box)
	{
		float closestX = clamp(circle.centre.x, box.points[0].x, box.points[2].x);
		float closestY = clamp(circle.centre.y, box.points[0].y, box.points[1].y);

		float d2 = (circle.centre.x - closestX) * (circle.centre.x - closestX) + (circle.centre.y - closestY) * (circle.centre.y - closestY);
		

		return(circle.radius*circle.radius >= d2);

	}

	glm::vec2 calculateNearestVector(Circle& circle,glm::vec2 edge,glm::vec2 point)
	{

		glm::vec2 edgeUnitVector = glm::normalize(edge);

		
		glm::vec2 circleToPoint = circle.centre - point;

		
		glm::vec2 nearest = point + glm::dot(edgeUnitVector, circleToPoint) * edgeUnitVector;

		

		return nearest;



	}

	bool circleQuadCollisionPass(Circle& circle, Box& box)
	{
		glm::vec2 nearestVector[4];

		
		
		for (int i = 0; i < 4; i++)
		{
			nearestVector[i] = calculateNearestVector(circle, box.dir[i], box.points[i]);


		}

	

		glm::vec2 clampedToEdges[4];

		for (int i = 0; i < 4; i++)
		{
			int j;
			if (i == 3)
				j = 0;
			else
				j = i + 1;

			clampedToEdges[i].x = clamp(nearestVector[i].x, box.points[i].x, box.points[j].x);
			
			clampedToEdges[i].y = clamp(nearestVector[i].y, box.points[i].y, box.points[j].y);
			
			
		}
		
		
		
		for (int i = 0; i < 4; i++)
		{

			if (getNearestDist(circle.centre, clampedToEdges[i]) <= circle.radius * circle.radius)
				return true;


		}

		return false;
	}


		
	void printVector(const glm::vec2 vector)
	{

		std::cout << vector.x << " X " << vector.y << " Y " << "\n";
	}

}