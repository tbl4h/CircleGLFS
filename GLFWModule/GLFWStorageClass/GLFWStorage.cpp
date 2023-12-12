//
// Created by mic on 03.12.23.
//

#include "GLFWStorage.h"


GLFWStorage::GLFWStorage() {
    _shaderVertex = glCreateShader( GL_VERTEX_SHADER );
    glShaderSource( _shaderVertex, 1, &shaderCodeVertex, nullptr );
    glCompileShader( _shaderVertex );

    _shaderFragment = glCreateShader( GL_FRAGMENT_SHADER );
    glShaderSource( _shaderFragment, 1, &shaderCodeFragment, nullptr );
    glCompileShader( _shaderFragment );

    _program = glCreateProgram();
    glAttachShader( _program, _shaderVertex );
    glAttachShader( _program, _shaderFragment );

    glLinkProgram( _program );
    glUseProgram( _program );

    glCreateVertexArrays( 1, &_vao );
    glBindVertexArray( _vao );

    _kBufferSize = sizeof(PerFrameData);


    glCreateBuffers(1, &_perFrameDataBuffer);
    glNamedBufferStorage(_perFrameDataBuffer, _kBufferSize, nullptr, GL_DYNAMIC_STORAGE_BIT);
    glBindBufferRange(GL_UNIFORM_BUFFER, 0, _perFrameDataBuffer, 0, _kBufferSize);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_POLYGON_OFFSET_LINE);
    glPolygonOffset(-1.0f, -1.0f);
}

GLFWStorage::~GLFWStorage() {
    glDeleteBuffers(1, &_perFrameDataBuffer);
    glDeleteProgram( _program );
    glDeleteShader( _shaderFragment );
    glDeleteShader( _shaderVertex );
    glDeleteVertexArrays( 1, &_vao );
}

GLuint GLFWStorage::getPerFrameDataBuffer() const {
    return _perFrameDataBuffer;
}

GLsizeiptr GLFWStorage::getKBufferSize() const {
    return _kBufferSize;
}
