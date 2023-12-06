//
// Created by mic on 03.12.23.
// Store all GPU pipeline components.
//

#ifndef CIRCLERENDER_GLFWSTORAGE_H
#define CIRCLERENDER_GLFWSTORAGE_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "../../glad/include/glad/glad.h"
#include "../../glad/src/glad.c"
#include "./../Shaders/Shaders.cpp"

class GLFWStorage {
public:
    GLFWStorage();
    ~GLFWStorage();

private:
    GLuint shaderVertex;
    GLuint shaderFragment;
    GLuint program;
    GLuint vao;

};


#endif //CIRCLERENDER_GLFWSTORAGE_H
