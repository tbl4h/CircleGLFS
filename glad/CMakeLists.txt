cmake_minimum_required(VERSION 3.1)
project(glad)

set(GLAD_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_library(glad ${GLAD_DIR}/src/glad.c)
target_include_directories(glad PUBLIC ${GLAD_DIR}/include)

install(TARGETS glad DESTINATION lib)
install(DIRECTORY ${GLAD_DIR}/include/ DESTINATION include)