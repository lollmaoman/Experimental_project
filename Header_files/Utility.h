#pragma once


#include"ResourceNamespace.h"
#include <glm/glm/glm.hpp>
#include<glm/glm/gtc/matrix_transform.hpp>
#include<glm/glm/gtc/type_ptr.hpp>
#include"triangle.h"
#include"input.h"
namespace Utility
{


	void printVector(glm::vec2 vector);

	
	glm::vec2 calculateNearestVector(Circle& circle, glm::vec2 edge, glm::vec2 point);
	float getMin(float x, float y, float z);

	
	float getMax(float x, float y, float z);
	float clamp(float valueToClamp, float left, float right);
	
	bool collisionPassTriangle(Triangle& t1, Triangle& t2);

	float getProjections(glm::vec2 point, glm::vec2 normal);

	bool collisionPassBox(Box& box1, Box& box2);

	bool circleBoxCollisionPass(Circle& circle, Box& box);
	bool circleQuadCollisionPass(Circle& circle, Box& box);

}