# Copyright (c) 2019 Ivan Blagopoluchnyy. Email: nuclearrazor@gmail.com

cmake_minimum_required(VERSION 3.0.2)
project(XSerial)

if(WIN32)
	add_definitions(-DUNICODE -D_UNICODE)
endif(WIN32)

if (APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

if(${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc" )
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

file(GLOB _SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
set (MAIN_FILE ${PROJECT_SOURCE_DIR}/example/com_port/main.cpp)
file(GLOB _HEADERS SYSTEM ${PROJECT_SOURCE_DIR}/src)

message(STATUS "Project path: " ${PROJECT_SOURCE_DIR})

set(EXECUTABLE ${PROJECT_NAME})
SET(BASEPATH "${CMAKE_SOURCE_DIR}")

include_directories(${_HEADERS} ${BASEPATH} ${PROJECT_SOURCE_DIR} ${_LIBS}})
add_executable(${EXECUTABLE} ${MAIN_FILE})
target_link_libraries(${PROJECT_NAME} ${_LIBS})

#cmake .. -G "Visual Studio 15 2017 Win64"