#ifndef TRIANGLE_COLLISION_H
#define TRIANGLE_COLLISION_H


#include <glm/glm/glm.hpp>
#include<glm/glm/gtc/matrix_transform.hpp>
#include<glm/glm/gtc/type_ptr.hpp>
#include"triangle.h"



float getProjections(glm::vec2 point, glm::vec2 normal);

float getMin(float x, float y, float z);


float getMax(float x, float y, float z);

bool checkCollisionSingleNormalT1(Triangle& t1, Triangle& t2, int index, int configuration);

bool checkCollisionSingleNormalT2(Triangle& t1, Triangle& t2, int index, int configuration);

bool performCollisionCheck(Triangle& t1, Triangle& t2);









#endif
