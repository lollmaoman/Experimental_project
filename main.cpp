#include<iostream>
#include <glm/glm/glm.hpp>
#include<glm/glm/gtc/matrix_transform.hpp>
#include<glm/glm/gtc/type_ptr.hpp>
#include"triangle.h"
#include"triangleCollision.h"



int main()
{
	
	
	Triangle triangle(glm::vec2(5.0f, 5.0f), glm::vec2(0.0f, 0.0f), glm::vec2(10.0f, 0.0f));
	
	

	Triangle triangle1(glm::vec2(-5.0f, -5.0f), glm::vec2(-7.0f, -9.0f), glm::vec2(-1.0f, 0.0f));
	

	std::cout << performCollisionCheck(triangle, triangle1);

	

	
}

