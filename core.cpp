#include"core.h"
#include"triangleCollision.h"
#include"input.h"

namespace Core
{
	
	Triangle* triangle;
	Triangle* triangle1;


	void defineShapes()
	{
		triangle = new Triangle(glm::vec2(-100.0f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec2(0.0f, 100.0f));
		triangle1 = new Triangle(glm::vec2(10.0f, 43.0f), glm::vec2(10.0f, 20.0f), glm::vec2(200.0f, -40.0f));
		Resources::addShader("basic", "triangleShape.vert", "triangleColor.frag");

		std::cout << performCollisionCheck(*triangle, *triangle1);

	}

	void setMatrices()
	{

		Resources::getShaderList();
		glm::mat4 projection = glm::ortho(-400.0f, 400.0f, -400.0f, 400.0f, -1.0f, 1.0f);
		Resources::accessShader("basic").Use();
		Resources::accessShader("basic").setMat4("projection", projection);


	}

	void render()
	{
		

		
		Resources::accessShader("basic").Use();
		glBindVertexArray(triangle->VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		
			glBindVertexArray(triangle1->VAO);
			glDrawArrays(GL_TRIANGLES, 0, 3);
		


	}

	

}