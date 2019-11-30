#CMAKE FOR GLFW
cmake_minimum_required(VERSION 2.0)

project(ChessScene)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

find_package (OpenGL REQUIRED)
find_library(GLFW3_LIBRARY glfw REQUIRED)
find_path(GLEW_INCLUDE_DIR GL/glew.h)
find_library(GLEW_LIBRARY GLEW glew REQUIRED)

set(SOURCE_FILES
	src/ShaderLoad.cpp
	src/Shader.cpp
	src/Main.cpp
)
include_directories(${PROJECT_SOURCE_DIR}/include/)


add_executable(ChessScene ${SOURCE_FILES})

if (UNIX)
    target_link_libraries (ChessScene
        ${GLFW3_LIBRARY}
	${OPENGL_LIBRARIES}
        ${GLEW_LIBRARY}
        pthread)
endif (UNIX)
