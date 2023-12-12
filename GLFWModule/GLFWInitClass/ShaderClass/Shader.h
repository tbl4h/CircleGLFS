//
// Created by mic on 12.12.23.
// Class represent single vertex shader.

#ifndef CIRCLERENDER_SHADER_H
#define CIRCLERENDER_SHADER_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

using std::string;

string getFileContent(const char * filename);

class Shader {
public:
    // Unique Id number reserved for needs GPU memory reservation.
    GLuint ID;
    Shader(const char* vertexFile, const char* fragmentFile);

    void Activate();
    void Delete();

};


#endif //CIRCLERENDER_SHADER_H
