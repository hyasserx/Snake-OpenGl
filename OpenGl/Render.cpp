#include "Render.h"



Renderer::Renderer()
{
}

void Renderer::Initialize(GLuint SCR_WIDTH, GLuint SCR_HEIGHT) {
	stepSize = 1.0;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	float vertices[] = {
		-0.0f,  0.5f, 0.0f,  // top left (x,y,z)
		0.9f, 0.0f, 0.0f,

		0.5f, -0.5f, 0.0f,  // bottom left Vertex
		0.1f, 0.9f, 0.0f,

		-0.5f, -0.5f, 0.0f,  //Bottom Right
		0.0f, 0.5f,1.0f

	};
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");

	glUseProgram(programID);
	MVPID = glGetUniformLocation(programID, "MVP");

	scaleMat = scale(0.5f, 0.5f, 0.5f);
	Tx = 0.0f;
	Ty = 0.0f;
	Tz = 0.0f;
	translateMat = translate(Tx, Ty, Tz);
	AngleZ = 0;
	Rz = rotate(AngleZ, 0.0f, 0.0f, 1.0f);
	ModelMatrix = translateMat * Rz * scaleMat;
	T2 = translate(-1.0f, 0.0f, 0.0f);
	ModelMatrix2 = T2 * scaleMat;

	MainCamera = Camera(
		vec3(0, 0, 5),
		vec3(0, 0, 0),
		vec3(0, 1, 0)
	);
	ViewMatrix = MainCamera.getViewMatrix();
	ProjectionMatrix = perspective(60.0f, (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 1000.0f);//3D 


	Time = glfwGetTime();


}

void Renderer::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(programID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (char*)(sizeof(float) * 3));
	ViewMatrix = MainCamera.getViewMatrix();
	MVP = ProjectionMatrix * ViewMatrix*ModelMatrix;
	glUniformMatrix4fv(MVPID, 1, GL_FALSE, &MVP[0][0]);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	MVP = ProjectionMatrix * ViewMatrix * ModelMatrix2;
	glUniformMatrix4fv(MVPID, 1, GL_FALSE, &MVP[0][0]);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void Renderer::Update() {
	GLfloat CurrentTime = glfwGetTime();
	GLfloat DeltaTime = CurrentTime - Time;
	Time = CurrentTime;
}

void Renderer::HandleKeyboard(int key, int Action) {

	if (key == GLFW_KEY_W)
	{
		
		ModelMatrix = translate(0.0f, (float)(stepSize / 10.0), 0.0f) * ModelMatrix;
	}
	if (key == GLFW_KEY_S)
	{
		
		ModelMatrix = translate(0.0f, (float)(-stepSize / 10.0), 0.0f) * ModelMatrix;

	}
	if (key == GLFW_KEY_D)
	{
		
		ModelMatrix = translate((float)(stepSize/10.0), 0.0f, 0.0f) * ModelMatrix;

	}
	if (key == GLFW_KEY_A)
	{
		
		ModelMatrix = translate((float)(-stepSize / 10.0), 0.0f, 0.0f) * ModelMatrix;

	}
	if (key == GLFW_KEY_Z)
	{
		ModelMatrix = rotate(10.0f, 0.0f, 0.0f, 1.0f)*ModelMatrix;
	}
	if (key == GLFW_KEY_X)
	{
		ModelMatrix = rotate(10.0f, 1.0f, 0.0f, 0.0f)*ModelMatrix;
	}
	if (key == GLFW_KEY_Y)
	{
		ModelMatrix = rotate(10.0f, 0.0f, 1.0f, 0.0f)*ModelMatrix;
	}
	if (key == GLFW_KEY_RIGHT)
	{
		MainCamera.Strafe(0.1);
	}
	if (key == GLFW_KEY_LEFT)
	{
		MainCamera.Strafe(-0.1);
	}
	if (key == GLFW_KEY_UP)
	{
		MainCamera.Walk(0.1);
	}
	if (key == GLFW_KEY_DOWN)
	{
		MainCamera.Walk(-0.1);
	}
	if (key == GLFW_KEY_U)
	{
		MainCamera.Fly(0.1);
	}
	if (key == GLFW_KEY_J)
	{
		MainCamera.Fly(-0.1);
	}
	if (key == GLFW_KEY_KP_6)
	{
		MainCamera.Yaw(1.0);
	}
	if (key == GLFW_KEY_KP_4)
	{
		MainCamera.Yaw(-1.0);
	}



};



void Renderer::Cleanup() {

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

Renderer::~Renderer()
{
}
