//
// Created by mic on 03.12.23.
// Initialize GLFW library.
//

#ifndef CIRCLERENDER_GLFWINIT_H
#define CIRCLERENDER_GLFWINIT_H
#include "../../glad/include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <cstdio>
#include <cstdlib>

static void errorCallback(int error, const char* description){
    fprintf( stderr, "Error: %s\n", description );
};

class GLFWInit {
public:
    GLFWInit();
    ~GLFWInit();
    void setWindow(GLFWwindow* window) ;
    void setDefaultKeys(GLFWwindow *window);

private:


};


#endif //CIRCLERENDER_GLFWINIT_H
