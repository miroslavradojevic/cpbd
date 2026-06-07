cmake_minimum_required(VERSION 3.20.1)
set(CMAKE_CONFIGURATION_TYPES Release)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(CPBD VERSION 0.0.1)

# manually point CMake variable OpenCV_DIR to the build
if (UNIX)
	set(OpenCV_DIR "$ENV{HOME}/opencv/build")
else()
	set(OpenCV_DIR "C:/opencv/build") # path where opencv is built
endif()

find_package(OpenCV REQUIRED)

if (OpenCV_FOUND)
	message("OpenCV version " ${OpenCV_VERSION})
	include_directories(${OpenCV_INCLUDE_DIRS})
	
	add_executable(cpbd src/main.cpp src/Input_parser.cpp)
	target_include_directories(cpbd PRIVATE ./src)
    target_link_libraries(cpbd ${OpenCV_LIBS})
else()
	message("OpenCV not found")
endif()

