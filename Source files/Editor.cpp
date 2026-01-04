#include"Editor.h"


namespace Editor
{
	
	float scaleX = 1.0f;
	float scaleY = 1.0f;

	Circle*mouse = nullptr;

	void initMouse(Circle* mouse)
	{
		Editor::mouse = mouse;
	}

	bool isNearBox(Box& box)
	{

		bool near = Utility::circleQuadCollisionPass(*mouse,box);
		bool drag = input::onLeftClickHold();
	
		return near && drag;


			
	}

	glm::mat4 scaleBox(Box& box)
	{
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


	}
}