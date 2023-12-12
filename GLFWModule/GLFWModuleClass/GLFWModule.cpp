//
// Created by mic on 09.12.23.
//

#include "GLFWModule.h"


GLFWModule::GLFWModule() {
    _initInstance.setWindow(_windowInstance.getWindow());
    _initInstance.setDefaultKeys(_windowInstance.getWindow());
    _storage = new GLFWStorage;
}

void GLFWModule::start() {
    while ( !glfwWindowShouldClose(GLFWWindow::_mainWindow) )
    {
        int width, height;
        glfwGetFramebufferSize(
                GLFWWindow::_mainWindow, &width, &height);
        glViewport(0, 0, width, height);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(GLFWWindow::_mainWindow);
        glfwPollEvents();
    }
}

GLFWModule::~GLFWModule() {
    delete(_storage);
}

void GLFWModule::start_2() {
    while (!glfwWindowShouldClose(GLFWWindow::_mainWindow)) {
        int width, height;
        glfwGetFramebufferSize(GLFWWindow::_mainWindow, &width, &height);
        const float ratio = width / (float) height;

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        const mat4 m = glm::rotate(glm::translate(mat4(1.0f), vec3(0.0f, 0.0f, -3.5f)), (float) glfwGetTime(),
                                   vec3(1.0f, 1.0f, 1.0f));
        const mat4 p = glm::perspective(45.0f, ratio, 0.1f, 1000.0f);

        PerFrameData perFrameData = {.mvp = p * m, .isWireframe = false};

        glNamedBufferSubData(_storage->getPerFrameDataBuffer(), 0, _storage->getKBufferSize(), &perFrameData);

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        perFrameData.isWireframe = true;
        glNamedBufferSubData(_storage->getPerFrameDataBuffer(), 0, _storage->getKBufferSize(), &perFrameData);

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        glfwSwapBuffers(GLFWWindow::_mainWindow);
        glfwPollEvents();
    }
}

