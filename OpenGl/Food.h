#pragma once
#include <glad/glad.h> //for 2017
#include <GLFW/glfw3.h> //for2017
//#include <gl/glew.h> //For Lower Than  2017
//#include <gl/glfw3.h> //For Lower Than  2017
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtx\transform.hpp>
class Food
{
public:
	Food();
	void Show();//Show The Food in Some Random Places
	void Special();// Handel Special case of Special Food Appearing
	~Food();
};

