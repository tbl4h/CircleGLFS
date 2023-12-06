//
// Created by mic on 03.12.23.
//

#include "GLFWStorage.h"


GLFWStorage::GLFWStorage() {
    shaderVertex = glCreateShader( GL_VERTEX_SHADER );
    glShaderSource( shaderVertex, 1, &shaderCodeVertex, nullptr );
    glCompileShader( shaderVertex );

    shaderFragment = glCreateShader( GL_FRAGMENT_SHADER );
    glShaderSource( shaderFragment, 1, &shaderCodeFragment, nullptr );
    glCompileShader( shaderFragment );

    program = glCreateProgram();
    glAttachShader( program, shaderVertex );
    glAttachShader( program, shaderFragment );

    glLinkProgram( program );
    glUseProgram( program );

    glCreateVertexArrays( 1, &vao );
    glBindVertexArray( vao );

    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
};

GLFWStorage::~GLFWStorage() {
    glDeleteProgram( program );
    glDeleteShader( shaderFragment );
    glDeleteShader( shaderVertex );
    glDeleteVertexArrays( 1, &vao );
}