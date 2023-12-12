//
// Created by mic on 03.12.23.
// Store all GPU pipeline components.
// Use Shaders.cpp file to load current shaders.
//

#ifndef CIRCLERENDER_GLFWSTORAGE_H
#define CIRCLERENDER_GLFWSTORAGE_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "./glad/glad.h"
#include "./../Shaders/Shaders.cpp"
#include <glm/glm.hpp>
#include <glm/ext.hpp>

using glm::mat4;

struct PerFrameData {
    mat4 mvp;
    int isWireframe;
};

class GLFWStorage {
public:
    GLFWStorage();
    ~GLFWStorage();

private:
    GLuint _shaderVertex;
    GLuint _shaderFragment;
    GLuint _program;
    GLuint _vao;
    GLuint _perFrameDataBuffer;
    GLsizeiptr _kBufferSize;
public:
    GLsizeiptr getKBufferSize() const;

public:
    GLuint getPerFrameDataBuffer() const;
};


#endif //CIRCLERENDER_GLFWSTORAGE_H
