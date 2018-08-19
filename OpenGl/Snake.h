#pragma once
#include <glad/glad.h> //for 2017
#include <GLFW/glfw3.h> //for2017
//#include <gl/glew.h> //For Lower Than  2017
//#include <gl/glfw3.h> //For Lower Than  2017
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtx\transform.hpp>
class Snake
{
public:
	Snake();
	void Move(); // Handels Movment Of Snake
	void Eat(); // What Happens When Snake Collides with Food -used inside Collide()-
	void Grow();// Grow Snake When It Collides with Food -used inside Eat()-
	void Collide();// Handdels all cases of Collisions 
	void Animation();// Bouns : Animitaion Handler 
	~Snake();
};

