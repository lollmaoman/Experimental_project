#ifndef TRIANGLE_H
#define TRIANGLE_H
#include<iostream>
#include <glm/glm/glm.hpp>
#include<glm/glm/gtc/matrix_transform.hpp>
#include<glm/glm/gtc/type_ptr.hpp>
#include<vector>
#include"Shader.h"
#include"ResourceNamespace.h"
struct Circle
{
	float aspectX = 1.0f;
	float aspectY = 1.0f;

	glm::vec2 centre;
	float radius;
	glm::vec2 centre_c;
	unsigned int total_vertices = 0;

	unsigned int VAO, VBO;

	Circle(glm::vec2 centre, float radius);

	void buildCircle();

	void printRadius();
	void printCentre();


};
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

struct Box
{
	float Cords[12];

	glm::vec2 points[4];
	glm::vec2 dir[4];
	glm::vec2 normals[4];
	glm::vec2 points_c[4];

	glm::vec2 scale = glm::vec2(1.0f);

	unsigned int VBO, VAO;

	Box(glm::vec2 pointA, glm::vec2 pointB, glm::vec2 pointC, glm::vec2 pointD);

	void computeDirections();
	
	void printNormals();
	void printDirections();
	void printPoints();

	void computeNormals();

	void buildTriangle();

	void buildBox();

	void updateBox();
	glm::vec2 centralAxis();
	


};

#endif