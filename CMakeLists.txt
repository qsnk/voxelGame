cmake_minimum_required(VERSION 3.29)
project(voxelGame)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} glfw OpenGL::GL GLEW::GLEW ${GLM_LIBRARIES})
