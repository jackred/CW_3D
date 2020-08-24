#CMAKE FOR GLFW
cmake_minimum_required(VERSION 2.8.4)

if(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 OLD)
endif(COMMAND cmake_policy)

project(ChessScene)

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )

message( "system name is: " ${CMAKE_SYSTEM} )
message( "system processor is: " ${CMAKE_SYSTEM_PROCESSOR} )

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  SET( LINUX 1)
  SET( APPLE 0)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  SET( LINUX 0)
  SET( APPLE 1 ) 
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  SET( WINDOWS 1)
endif()

link_directories(${PROJECT_BINARY_DIR})

find_package (OpenGL REQUIRED)
find_library(GLFW3_LIBRARY glfw REQUIRED)

if(APPLE OR LINUX)
  find_path(GLEW_INCLUDE_DIR GL/glew.h)
  find_library(GLEW_LIBRARY GLEW glew REQUIRED)
endif(APPLE OR LINUX)


include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories(${PROJECT_SOURCE_DIR}/shaders)
include_directories(${PROJECT_SOURCE_DIR}/lib)

if(WINDOWS)
  include_directories(${PROJECT_SOURCE_DIR}/lib/win/glew/include/)
endif(WINDOWS)

if(APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${GLEW_INCLUDE_DIRS}")
endif(APPLE)

set(SOURCE_FILES
  src/Main.cpp
  src/Window.cpp
  src/App.cpp
  src/Camera.cpp
  src/ShaderLoad.cpp
  src/Shader.cpp
  src/Mesh.cpp
  src/ChessScene.cpp
  )


add_executable(ChessScene ${SOURCE_FILES})
if(WINDOWS)
  target_link_libraries(${target} glfw glew32s ${GLFW_LIBRARIES} ) 
endif(WINDOWS)


if (UNIX)
  target_link_libraries (ChessScene
    #glfw
    ${GLEW_LIBRARY}
    ${GLFW3_LIBRARY}
    ${OPENGL_LIBRARIES}
    pthread)
endif (UNIX)

foreach(dir ${dirs})
  message(STATUS "dir='${dir}'")
endforeach()
