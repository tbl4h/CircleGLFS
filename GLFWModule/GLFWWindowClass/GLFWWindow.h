//
// Created by mic on 03.12.23.
// Create Window and all needed context.
//

#ifndef CIRCLERENDER_GLFWWINDOW_H
#define CIRCLERENDER_GLFWWINDOW_H

#include <GLFW/glfw3.h>


class GLFWWindow {
public:
    explicit GLFWWindow(int width = 800, int heights = 600, const char * name = "Window");
    ~GLFWWindow();
    GLFWwindow* getWindow();


public:
    static GLFWwindow* _mainWindow;
    int _mainWindowWidth;
    int _mainWindowHeight;


};

#endif //CIRCLERENDER_GLFWWINDOW_H
