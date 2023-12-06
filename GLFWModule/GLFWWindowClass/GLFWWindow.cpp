//
// Created by mic on 03.12.23.
//

#include "GLFWWindow.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>

GLFWWindow::GLFWWindow(unsigned int width, unsigned int heights, const char * name) {


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(width, heights, name, nullptr, nullptr);
    if (!_window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }


};
GLFWWindow::~GLFWWindow() {
    glfwDestroyWindow( _window );
}



GLFWwindow*  GLFWWindow::getWindow() {
    return _window;
}