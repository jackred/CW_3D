#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <unistd.h>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void errorCallbackGLFW(int error, const char* description) {
  std::cout << "Error GLFW: " << description << "\n";
}

void endProgram(GLFWwindow* window) {
  glfwMakeContextCurrent(window);
  glfwTerminate();
}

void debugGL() {
  //Output some debugging information
  std::cout << "VENDOR: " << (char *)glGetString(GL_VENDOR) << std::endl;
  std::cout << "VERSION: " << (char *)glGetString(GL_VERSION) << std::endl;
  std::cout << "RENDERER: " << (char *)glGetString(GL_RENDERER) << std::endl;

  // Enable Opengl Debug
  //glEnable(GL_DEBUG_OUTPUT);
  glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
  glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, true);
}

int main()
{
  bool running = true;
  // glfw: initialize and configure
  // ------------------------------
  if (!glfwInit()) {							// Checking for GLFW
    std::cout << "Could not initialise GLFW...";
    return 0;
  }
  glfwSetErrorCallback(errorCallbackGLFW);
  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_SAMPLES, 2);
  glfwWindowHint(GLFW_STEREO, GL_FALSE);
	
  // glfw window creation
  // --------------------
  GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
  if (!window) {
    std::cout << "Could not initialise GLFW...";
    endProgram(window);
    return 0;
  }

  glfwMakeContextCurrent(window);

  glewExperimental = GL_TRUE;					// hack: catching them all - forcing newest debug callback (glDebugMessageCallback)
  GLenum errGLEW = glewInit();
  if (GLEW_OK != errGLEW) {					// Problems starting GLEW?
    std::cout << "Could not initialise GLEW...";
    endProgram(window);
    return 0;
  }

  do {										// run until the window is closed
    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

    running &= (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_RELEASE);	// exit if escape key pressed
    running &= (glfwWindowShouldClose(window) != GL_TRUE);
  } while (running);
  
  return 0;
}



