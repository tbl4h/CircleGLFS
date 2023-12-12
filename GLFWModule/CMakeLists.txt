# Ustaw katalog dla wyszukiwania modułów CMAKE
set(CMAKE_MODULE_PATH ${CMAKE_MODULES_PATH} ./../CMAKE_MODULE_PATH)

# Wyszukaj i ustaw ścieżki do pakietów OpenGL, GLFW i GLEW
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(Vulkan REQUIRED)
# Wyszujkaj bibliotekę GLAD
find_package(glad REQUIRED)




# Dodaj bibliotekę
add_library(GLFWModule
        ./GLFWInitClass/GLFWInit.cpp
        ./GLFWWindowClass/GLFWWindow.cpp
        ./GLFWStorageClass/GLFWStorage.cpp
        ./GLFWModuleClass/GLFWModule.cpp
        GLFWInitClass/ShaderClass/Shader.cpp
        GLFWInitClass/ShaderClass/Shader.h
)

target_include_directories(GLFWModule PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/GLFWModule/GLFWInitClass/GLFWInit.h
        ${CMAKE_CURRENT_SOURCE_DIR}/GLFWModule/GLFWWindowClass/GLFWWindow.h
        ${CMAKE_CURRENT_SOURCE_DIR}/GLFWModule/GLFWStorageClass/GLFWStorage.h
        ${CMAKE_CURRENT_SOURCE_DIR}/GLFWModule/GLFWModuleClass/GLFWModule.h
)

# Dodaj ścieżki do nagłówków OpenGL, GLFW i GLEW
include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

# Dodaj biblioteki OpenGL, GLFW i GLEW
target_link_libraries(GLFWModule ${OPENGL_LIBRARIES} glfw GLEW)
# Dodaj biblitekę GLAD
target_link_libraries(GLFWModule glad)