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
	glm::vec2 newPosition = glm::vec2(0.0f);
	 
	glm::vec2 point_c[3];


	
	unsigned int VBO, VAO;

	
	
	Triangle(glm::vec2 first, glm::vec2 second, glm::vec2 third);
	void computeDirections();
	

	glm::vec2 getPointByIndex(int i);


	glm::vec2 getNormalByIndex(int i);


	void computeNormals();
	

	void printDirections();

	bool checkClockwise();

	void printNormals();


	void printPoints();

	void buildTriangle();


};


#endif