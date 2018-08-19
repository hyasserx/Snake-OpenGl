#include <glad/glad.h> //for 2017
#include <GLFW/glfw3.h> //for2017
//#include <gl/glew.h> //For Lower Than  2017
//#include <gl/glfw3.h> //For Lower Than  2017
#include <Windows.h>
#include<glm\glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm\gtx\transform.hpp>
#include <iostream>
#include"Camera.h"
#include "Render.h"



GLuint SCR_WIDTH = 800;
GLuint SCR_HEIGHT = 600;

int Key = -1;
double posX = SCR_WIDTH/2;
double posY = SCR_HEIGHT/2;
bool mouseClicked = false;
Camera MainCamera; 



bool InitGraphics();
void HandleKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods);
Renderer* renderer;

int main( void )
{
	InitGraphics();
	return 0;
}

bool InitGraphics() {

	renderer = new Renderer();
	GLFWwindow* window;
	// glfw: initialize and configure
	// ------------------------------
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return false;
	}
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

														 // glfw window creation
														 // --------------------
	 window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Snake", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	//For Less Than 2017
	/*
	// ******************** Initialize GLEW ******************** //
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return false;
	}
	//----End Of GLEW for less than 2017 Users ------- 
	*/

	//For 2017
	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	//----End of Glad for 2017 Users ---- 
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glfwSetKeyCallback(window, &HandleKeyboard);

	// Initialize OpenGl
	renderer->Initialize(SCR_WIDTH,SCR_HEIGHT);
	do {

		renderer->Draw();
		renderer->Update();
		glfwSwapBuffers(window); 
		glfwPollEvents();
	}
	while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

	glfwTerminate();
	delete renderer;
	return true;

}
void HandleKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS || action == GLFW_REPEAT)
		renderer->HandleKeyboard(key, action);
}