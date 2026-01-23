#include"core.h"
#include"input.h"
#include"triangle.h"
#include"Utility.h"
#include"viewport.h"
#include"Editor.h"
namespace Core
{

	Triangle* triangle;
	Triangle* triangle1;

	Box* mouseBorder;
	Box* box;
	Box* box1;

	Circle* c;

	viewport screen;

	


	const float velocity = 100.0f;

	float translatePositionX = 0.0f;
	float translatePositionY = 0.0f;

	float mouseBorderTranslateX = 0.0f;
	float mouseBorderTranslateY = 0.0f;
	bool first = true;

	float deltaTime = 0.0f;
	float lastFrame = 0;

	
	void setViewPort(GLFWwindow *window)
	{
		screen.initViewport(window);
		screen.height = 600;
		screen.width = 800;

		screen.static_l = 100.0f;
		screen.d = 100.0f;

		screen.slopeX = 2 * screen.l /(float)screen.width;
		screen.slopeY = -2 * screen.d /(float)screen.height;

		screen.updateViewport(screen.width, screen.height);
	}

	void defineShapes()
	{

		
		triangle = new Triangle(glm::vec2(-20.0f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec2(0.0f, 20.0f));
		triangle1 = new Triangle(glm::vec2(20.0f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec2(0.0f, 20.0f));
		mouseBorder = new Box(glm::vec2(0.0f, 0.001f), glm::vec2(0.001f, 0.001f), glm::vec2(0.001f, 0.0f),glm::vec2(0.0f,0.0f));
		
		box = new Box(glm::vec2(-10.0f, 12.0f), glm::vec2(10.0f, 10.0f), glm::vec2(10.0f, -10.0f), glm::vec2(-10.0f, -15.0f));
		box1 = new Box(glm::vec2(0.0f, 50.0f), glm::vec2(70.0f, 30.0f), glm::vec2(50.0f, -20.0f), glm::vec2(0.0f, 0.0f));

		c = new Circle(glm::vec2(0.0f, 0.0f),1.5f);
		
		Resources::addShader("basic", "Shaders\\triangleShape.vert", "Shaders\\triangleColor.frag");

		Resources::addShader("basic1", "Shaders\\triangleShape1.vert", "Shaders\\triangleColor.frag");

		Resources::addShader("border", "Shaders\\border.vert", "Shaders\\triangleColor.frag");

		Editor::initMouse(c);

        
	}
	
	void setMatrices()
	{

		

		
		glm::mat4 identity = glm::mat4(1.0f);

		Editor::scaleBox(*box);
		glm::mat4 translateBox = glm::translate(identity, glm::vec3(translatePositionX, translatePositionY, 0.0f));
		glm::mat4 borderTranslate = glm::translate(identity, glm::vec3(mouseBorderTranslateX, mouseBorderTranslateY, 0.0f));
		
		glm::mat4 edit = translateBox*Editor::getScaleMatrix(*box) ;

		Resources::accessShader("basic").Use();
		Resources::accessShader("basic").setMat4("projection", screen.get2DProjection());
	//	Resources::accessShader("basic").setMat4("model", translateBox);
		Resources::accessShader("basic").setMat4("model", edit);

		Resources::accessShader("basic1").Use();
		Resources::accessShader("basic1").setMat4("projection",screen.get2DProjection());

		Resources::accessShader("border").Use();
		Resources::accessShader("border").setMat4("projection", screen.get2DProjection());
		Resources::accessShader("border").setMat4("model",borderTranslate);
		
		

	}

	void update()
	{

		
		

		Utility::calculateDeltaTime();
		float deltaTime = Utility::getDeltaTime();

		if (input::onPressed(GLFW_KEY_D))
		{
			translatePositionX += velocity * deltaTime;
			for (int i = 0; i < 3; i++)
			{
				
				triangle->point[i].x = triangle->point_c[i].x + translatePositionX;
				
			}

			for (int i = 0; i < 4; i++)
			{
				box->points[i].x = box->points_c[i].x+translatePositionX;

			}

			
		}

		if (input::onPressed(GLFW_KEY_A))
		{
			translatePositionX -= velocity * deltaTime;
			
			for (int i = 0; i < 3; i++)
			{
				triangle->point[i].x = triangle->point_c[i].x + translatePositionX;
				
			}

			for (int i = 0; i < 4; i++)
			{
				box->points[i].x = box->points_c[i].x + translatePositionX;

			}
		}

		if (input::onPressed(GLFW_KEY_W))
		{
			translatePositionY += velocity * deltaTime;
			for (int i = 0; i < 3; i++)
			{
				triangle->point[i].y = triangle->point_c[i].y + translatePositionY;
				
			}

			for (int i = 0; i < 4; i++)
			{
				box->points[i].y = box->points_c[i].y + translatePositionY;

			}
		}

		if (input::onPressed(GLFW_KEY_S))
		{
			translatePositionY -=  velocity*deltaTime;
			

			for (int i = 0; i < 3; i++)
			{
				triangle->point[i].y = triangle->point_c[i].y + translatePositionY;
				

			}

			for (int i = 0; i < 4; i++)
			{
				box->points[i].y = box->points_c[i].y + translatePositionY;


			}
			
		}
	//	box->printPoints();
		
		

		input::updateCursorPos(screen);
		input::setCallbacks();
		
		screen.setCallback();
		
	//	box->updateBox();
	

		
		
		    mouseBorderTranslateX = (float)input::cursorViewportX ;
			mouseBorderTranslateY = (float)input::cursorViewportY;
		
		
		c->centre = glm::vec2(mouseBorderTranslateX, mouseBorderTranslateY);
		
	//	std::cout << input::xOffset << " " << input::yOffset << "\n";


	}
	float getDeltaTime()
	{
		return deltaTime;
	}
	void render()
	{

		
	
	
		  Shader shader = Resources::getShader("basic");
		  shader.Use();
		
		  
		  Resources::accessShader("basic").Use();
		
		  Resources::accessShader("basic").setBool("collide", Utility::circleQuadCollisionPass(*c, *box));
		  glBindVertexArray(box->VAO);
		  glDrawArrays(GL_TRIANGLES, 0, 6);

		
		  Resources::accessShader("basic1").Use();
		  glBindVertexArray(box1->VAO);
		  glDrawArrays(GL_TRIANGLES, 0, 6);
		 
		  Resources::accessShader("border").Use();
		  glBindVertexArray(c->VAO);
		//  glDrawArrays(GL_TRIANGLES, 0, c->total_vertices);
		

	}
	


}

/*

edit mode press v to activate.
once activated we can select different terrain types like ground,spikes etc. to add anywhere on the map
also by dragging mouse we can resize it however we want and also delete it.









*/