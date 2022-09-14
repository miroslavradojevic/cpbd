cmake_minimum_required(VERSION 3.20.1)
set(CMAKE_CONFIGURATION_TYPES Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

project(CPBD VERSION 0.0.1)

if (UNIX)
	#set(OpenCV_DIR "$ENV{HOME}/opencv-build/")
else()
	#set(OpenCV_DIR "C:/path/to/opencv/build/")
endif()

find_package(OpenCV REQUIRED)

if (OpenCV_FOUND)
	message("OpenCV version " ${OpenCV_VERSION})
	
	add_executable(cpbd src/main.cpp)
else()
	message("OpenCV not found")
endif()

