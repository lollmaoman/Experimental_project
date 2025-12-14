#include"core.h"
#include"triangleCollision.h"
#include"input.h"
#include"triangle.h"

namespace Core
{

	Triangle* triangle;
	Triangle* triangle1;

	const float velocity = 100.0f;
	float translatePositionX = 0.0f;
	float translatePositionY = 0.0f;


	void defineShapes()
	{
		triangle = new Triangle(glm::vec2(-100.0f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec2(0.0f, 100.0f));
		triangle1 = new Triangle(glm::vec2(-100.0f, 0.0f), glm::vec2(100.0f, 0.0f), glm::vec2(0.0f, 100.0f));
		Resources::addShader("basic", "triangleShape.vert", "triangleColor.frag");

		Resources::addShader("basic1", "triangleShape1.vert", "triangleColor.frag");


	}

	void setMatrices()
	{


		glm::mat4 projection = glm::ortho(-400.0f, 400.0f, -400.0f, 400.0f, -1.0f, 1.0f);
		glm::mat4 identity = glm::mat4(1.0f);


		glm::mat4 translateX = glm::translate(identity, glm::vec3(translatePositionX, translatePositionY, 0.0f));

		Resources::accessShader("basic").Use();
		Resources::accessShader("basic").setMat4("projection", projection);
		Resources::accessShader("basic").setMat4("model", translateX);


		Resources::accessShader("basic1").Use();
		Resources::accessShader("basic").setMat4("projection", projection);

	}

	void update(float deltaTime)
	{
		if (input::onPressed(GLFW_KEY_D))
		{
			translatePositionX += velocity * deltaTime;
			for (int i = 0; i < 3; i++)
			{
				triangle->point[i].x += velocity * deltaTime;
			}

		}

		if (input::onPressed(GLFW_KEY_A))
		{
			translatePositionX -= velocity * deltaTime;
			
			for (int i = 0; i < 3; i++)
			{
				triangle->point[i].x -= velocity * deltaTime;
			}
		}

		if (input::onPressed(GLFW_KEY_W))
		{
			translatePositionY += velocity * deltaTime;
			for (int i = 0; i < 3; i++)
			{
				triangle->point[i].y += velocity * deltaTime;
			}
		}

		if (input::onPressed(GLFW_KEY_S))
		{
			translatePositionY -= velocity * deltaTime;
			
			for (int i = 0; i < 3; i++)
			{
				triangle->point[i].y -= velocity * deltaTime;
			}

		}

		  
			
			
		
	}

	void render()
	{
		Shader shader =Resources::getShader("basic");

		shader.Use();
		shader.setBool("collide", performCollisionCheck(*triangle, *triangle1));

		

		
		glBindVertexArray(triangle->VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		Resources::accessShader("basic1").Use();
	      glBindVertexArray(triangle1->VAO);
	      glDrawArrays(GL_TRIANGLES, 0, 3);
	

	}

	

}

/*

edit mode press v to activate.
once activated we can select different terrain types like ground,spikes etc. to add anywhere on the map
also by dragging mouse we can resize it however we want and also delete it.









*/