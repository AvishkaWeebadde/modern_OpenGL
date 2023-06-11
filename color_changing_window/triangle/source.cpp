#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<cmath>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void changeColor();

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float diff = 0.0f; // Declare time variable here


int main() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Triangle", NULL, NULL);
	if (window == NULL) {
		std::cout << " Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	while (!glfwWindowShouldClose(window)) {
		processInput(window);
		changeColor();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

void changeColor() {
	// Update clear color based on time
	float red = (sin(diff) + 1.0f) * 0.5f;    // Varying between 0.0f and 1.0f
	float green = (cos(diff) + 1.0f) * 0.5f;  // Varying between 0.0f and 1.0f
	float blue = 0.3f;                         // Fixed blue component

	// Set clear color
	glClearColor(red, green, blue, 1.0f);

	// Clear the color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	// Perform other rendering operations

	// Increment time for the next frame
	diff += 0.001f;
}
