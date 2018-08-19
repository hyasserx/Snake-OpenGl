#pragma once
#include <glad/glad.h> //for 2017
#include <GLFW/glfw3.h> //for2017
//#include <gl/glew.h> //For Lower Than  2017
//#include <gl/glfw3.h> //For Lower Than  2017
#include "shader.hpp"
#include "Camera.h"

#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtx\transform.hpp>

using namespace glm;

class Renderer
{
	GLuint VAO;
	GLuint VBO;
	GLuint programID;
	GLuint BufferObjectID;
	GLuint MVPID;

	mat4 scaleMat, translateMat, T2, Rz;
	mat4 MVP, ViewMatrix, ProjectionMatrix, ModelMatrix, ModelMatrix2;

	GLfloat Tx, Ty, Tz, AngleZ;
	GLfloat stepSize;
	GLfloat Time;

	Camera MainCamera;

public:
	Renderer();
	~Renderer();

	void Initialize(GLuint, GLuint);
	void Draw();
	void Update();
	void HandleKeyboard(int, int);
	void Cleanup();
};
