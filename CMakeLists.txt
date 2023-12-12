cmake_minimum_required(VERSION 3.26)
project(CircleRender)

set(CMAKE_CXX_STANDARD 20)

# Dodaj podkatalog, w którym znajduje się GLFWModule
add_subdirectory(./GLFWModule/)


add_executable(CircleRender main.cpp)
# Dodaj bibliotekę użytkownika odpowiedzialną za obsługę GLFW
target_link_libraries(CircleRender GLFWModule)

