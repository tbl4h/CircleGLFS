//
// Created by mic on 03.12.23.
//

#include "GLFWWindow.h"
#include <GLFW/glfw3.h>
#include <cstdlib>

GLFWwindow* GLFWWindow::_mainWindow = nullptr;

GLFWWindow::GLFWWindow(int width, int heights, const char * name):_mainWindowWidth{width},_mainWindowHeight{heights}
{


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWWindow::_mainWindow = glfwCreateWindow(_mainWindowWidth, _mainWindowHeight, name, nullptr, nullptr);
    if (!_mainWindow) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }


}
GLFWWindow::~GLFWWindow() {
    glfwDestroyWindow( GLFWWindow::_mainWindow );
}



GLFWwindow*  GLFWWindow::getWindow() {
    return _mainWindow;
}