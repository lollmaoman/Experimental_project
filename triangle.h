#ifndef TRIANGLE_H
#define TRIANGLE_H
#include<iostream>
#include <glm/glm/glm.hpp>
#include<glm/glm/gtc/matrix_transform.hpp>
#include<glm/glm/gtc/type_ptr.hpp>
#include<vector>
#include"Shader.h"


struct Triangle
{
	



	glm::vec2 point[3];
	glm::vec2 dir[3];
	glm::vec2 normal[3];
	
	
	
	

	Triangle(glm::vec2 first, glm::vec2 second, glm::vec2 third)
	{
		point[0] = first;
		point[1] = second;
		point[2] = third;


		computeDirections();
		computeNormals();
	}

	void computeDirections()
	{
		dir[0] = point[1] - point[0];
		dir[1] = point[2] - point[1];
		dir[2] = point[0] - point[2];


		
	}
	
	glm::vec2 getPointByIndex(int i)
	{
		return point[i];

	}

	glm::vec2 getNormalByIndex(int i)
	{
		return normal[i];

	}


	void computeNormals()
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

	void printDirections()
	{
		for (int i = 0; i < 3; i++)
		{
			std::cout << dir[i].x << " " << dir[i].y << "\n";

		}
		

	}

	bool checkClockwise()
	{
	
		float area;
		
		area = glm::determinant(glm::mat3{ 1.0f,1.0f,1.0f,
		   point[0].x,point[1].x,point[2].x,
		   point[0].y,point[1].y,point[2].y, });

		
		return(area < 0);

	}

	void printNormals()

	{
		for (int i = 0; i < 3; i++)
		{
			std::cout << normal[i].x << " " << normal[i].y << "\n";

		}
	}

	void printPoints()
	{
		for (int i = 0; i < 3; i++)
		{
			std::cout << point[i].x << " " << point[i].y << " \n";
		}
	}
};


#endif