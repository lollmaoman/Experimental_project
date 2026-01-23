#pragma once

#include<iostream>
#include"input.h"
#include"Utility.h"
#include"triangle.h"

namespace Editor
{
	extern Circle *mouse;
	void initMouse(Circle* mouse);
	void scaleBox(Box& box);
	bool isNearBox(Box& box);
	glm::mat4 getScaleMatrix(Box& box);








}