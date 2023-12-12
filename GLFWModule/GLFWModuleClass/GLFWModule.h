//
// Created by mic on 09.12.23.
// Combine all GLFWModule classes and make it usefully in program.
//

#ifndef CIRCLERENDER_GLFWMODULE_H
#define CIRCLERENDER_GLFWMODULE_H
#include "./../GLFWInitClass/GLFWInit.h"
#include "./../GLFWWindowClass/GLFWWindow.h"
#include "./../GLFWStorageClass/GLFWStorage.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>

using glm::vec3;


class GLFWModule {
public:
    GLFWModule();
    void start();
    void start_2();
    ~GLFWModule();
private:
    GLFWInit _initInstance;
    GLFWWindow _windowInstance;
    GLFWStorage* _storage;
};


#endif //CIRCLERENDER_GLFWMODULE_H
