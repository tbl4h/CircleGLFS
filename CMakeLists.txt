cmake_minimum_required(VERSION 3.26)
project(CircleRender)

set(CMAKE_CXX_STANDARD 20)

# Wyszukaj i ustaw ścieżki do pakietów OpenGL, GLFW i GLEW
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(Vulkan REQUIRED)


# Dodaj ścieżki do nagłówków OpenGL, GLFW i GLEW
include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

add_executable(CircleRender main.cpp
        GLFWModule/Shaders/Shaders.cpp
        GLFWModule/GLFWInitClass/GLFWInit.cpp
        GLFWModule/GLFWInitClass/GLFWInit.h
        GLFWModule/GLFWWindowClass/GLFWWindow.cpp
        GLFWModule/GLFWWindowClass/GLFWWindow.h
        GLFWModule/GLFWStorageClass/GLFWStorage.cpp
        GLFWModule/GLFWStorageClass/GLFWStorage.h)

# Dodaj biblioteki OpenGL, GLFW i GLEW
target_link_libraries(CircleRender ${OPENGL_LIBRARIES} glfw GLEW)

#if (glfwInit() != GLFW_TRUE) {