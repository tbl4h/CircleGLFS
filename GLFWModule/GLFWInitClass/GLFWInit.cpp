//
// Created by mic on 03.12.23.
//

#include "GLFWInit.h"

GLFWInit::GLFWInit() {
    glfwSetErrorCallback(
            errorCallback
    );
    if ( !glfwInit() )
        exit( EXIT_FAILURE );
}

GLFWInit::~GLFWInit() {
    glfwTerminate();
}
void GLFWInit::setWindow(GLFWwindow *window) {
    glfwMakeContextCurrent( window );
    // Use Glad library to load opengl.
    gladLoadGL();
    // Sets swap interval between front and back buffer.
    glfwSwapInterval( 1 );
}

void GLFWInit::setDefaultKeys(GLFWwindow *window) {
    glfwSetKeyCallback(
            window,
            [](GLFWwindow *window_, int key, int scancode, int action, int mods) {
                if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                    glfwSetWindowShouldClose(window_, GLFW_TRUE);
            }
    );
}