#include"Editor.h"
#include"Utility.h"

namespace Editor
{
	
	float scaleX = 1.0f;
	float scaleY = 1.0f;

	glm::vec2 scale = glm::vec2(1.0f);
	glm::mat4 scaleValue = glm::mat4(1.0f);

	Circle*mouse = nullptr;

	void initMouse(Circle* mouse)
	{
		Editor::mouse = mouse;
	}

	bool isNearBox(Box& box,int click)
	{

		bool near = Utility::circleQuadCollisionPass(*mouse,box);
		bool dragLeft = input::onLeftClickHold();
		bool dragRight = input::onRightClickHold();

		
		if (click == 0)
			return near && dragLeft;

		else
			return near && dragRight;
		

			
	}

	glm::vec2 centralAxis(Box &box)
	{
		glm::vec2 centre = glm::vec2(0.0f);
		for (int i = 0; i < 4; i++)
		{
			centre.x += box.points[i].x;
			centre.y += box.points[i].y;

		}

		centre.x /= 4.0f;
		centre.y /= 4.0f;

		return centre;
	}
	glm::mat4 getScaleMatrix(Box& box)
	{
		return scaleValue;

	}
	void scaleBox(Box& box)
	{
		 glm::mat4 identity = glm::mat4(1.0f);
		 glm::vec2 centre = centralAxis(box);

		 

		 if (isNearBox(box, 0))
		 {

			 float scaleTempX = 1.0f + 7.0f * Utility::getDeltaTime();
			 float scaleTempY = 1.0f + 7.0f * Utility::getDeltaTime();

			 scaleX *= scaleTempX;

			 scaleY *= scaleTempY;

			 scaleValue = glm::scale(identity, glm::vec3(scaleX, scaleY, 1.0f));
			 scale = glm::vec2(scaleTempX, scaleTempY);


			 for (int i = 0; i < 4; i++)
			 {
				 box.points[i] -= centre;
			 }

			 for (int i = 0; i < 4; i++)
			 {
				 box.points[i] *= scale;
				 box.points_c[i] *= scale;
			 }

			 for (int i = 0; i < 4; i++)
				 box.points[i] += centre;
		 }
		 else
		 {
			 scale = glm::vec2(1.0f);
			 scaleValue = glm::scale(identity, glm::vec3(scaleX, scaleY, 1.0f));

			 //scaleValue = 1.0f / scaleValue;
			 //scale = 1.0f / scale;

			 for (int i = 0; i < 4; i++)
			 {
				 box.points[i] -= centre;
			 }

			 for (int i = 0; i < 4; i++)
			 {
				 box.points[i] *= scale;
				 box.points_c[i] *= scale;
			 }

			 for (int i = 0; i < 4; i++)
				 box.points[i] += centre;
		 }
			if (isNearBox(box,1))
			{
				float scaleTempX = 1.0f + 7.0f * Utility::getDeltaTime();
				float scaleTempY = 1.0f + 7.0f * Utility::getDeltaTime();

				scaleX *= scaleTempX;

				scaleY *= scaleTempY;

				

				scaleX /= (scaleTempX * scaleTempX);
				scaleY /= (scaleTempY * scaleTempY);

				scaleTempX = 1.0f / scaleTempX;
				scaleTempY = 1.0f / scaleTempY;

				scaleValue = glm::scale(identity, glm::vec3(scaleX, scaleY, 1.0f));
				scale = glm::vec2(scaleTempX, scaleTempY);

				std::cout << "called \n";

			}

			else
			{
				scale = glm::vec2(1.0f);
				scaleValue = glm::scale(identity, glm::vec3(scaleX, scaleY, 1.0f));

				//scaleValue = 1.0f / scaleValue;
				//scale = 1.0f / scale;

				for (int i = 0; i < 4; i++)
				{
					box.points[i] -= centre;
				}

				for (int i = 0; i < 4; i++)
				{
					box.points[i] *= scale;
					box.points_c[i] *= scale;
				}

				for (int i = 0; i < 4; i++)
					box.points[i] += centre;

				//	scaleValue = 1.0f / scaleValue;
				//	scale = glm::vec2(1.0f / scale.x, 1.0f / scale.y);



			}
		
		/*
		if (isNearBox(box))
		{
			glm::mat4 identity = glm::mat4(1.0f);
			scaleX *= 1.1f;
			scaleY *= 1.1f;
			
			glm::mat4 scale_value = glm::scale(glm::mat4(1.0f), glm::vec3(scaleX, scaleY, 1.0f));

			box.scale = glm::vec2(1.002f);
			std::cout << "HEERE \n";
			return scale_value;
		}

		else
		{
			box.scale = glm::vec2(1.0f);
			return glm::scale(glm::mat4(1.0f), glm::vec3(scaleX, scaleY, 1.0f));
		}
		*/

	}
}