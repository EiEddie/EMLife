cmake_minimum_required(VERSION 3.19)
project(EMLife)


set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/dist")

if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "debug")
	add_definitions(-DDEBUG)
	message(STATUS "Add macro \"DEBUG\"")
endif()


include_directories("${PROJECT_SOURCE_DIR}/include")
file(GLOB_RECURSE SRC_FILE "${PROJECT_SOURCE_DIR}/src/*.cpp")

if(SRC_FILE)
	add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILE})
endif()
