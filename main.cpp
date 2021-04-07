#include <glad\glad.h>
#include <GLFW\glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// constants
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // initialize and configure GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create GLFW window
    GLFWwindow* window = glfwCreateWindow(800, 600, " OpenGL vase", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // resize viewport on window resize and first display
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // initialize GLAD: loading all pointers to OpenGL functions
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // create viewport
    glViewport(0, 0, 800, 600);

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        // checking and processing events, exchanging the contents of front- and back- buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // clear all resources allocated to GLFW
    glfwTerminate();

    return 0;
}

// processing of all input events
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// whenever the window is resized this callback function is called
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // width and height will be significantly larger than specified on Retina displays
    glViewport(0, 0, width, height);
}
