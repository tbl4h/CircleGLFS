//
// Created by mic on 03.12.23.
// Create Window and all needed context.
//

#ifndef CIRCLERENDER_GLFWWINDOW_H
#define CIRCLERENDER_GLFWWINDOW_H

#include <GLFW/glfw3.h>


class GLFWWindow {
public:
    GLFWWindow(unsigned int width, unsigned int heights, const char * name = "Window");
    ~GLFWWindow();
    GLFWwindow* getWindow();

private:
    GLFWwindow* _window;

};


#endif //CIRCLERENDER_GLFWWINDOW_H
