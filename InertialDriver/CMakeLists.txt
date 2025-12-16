cmake_minimum_required(VERSION 2.84)
set(CMAKE_CXX_STANDARD 11)
project(inertialdriver)



include_directories(include)

add_library(libmyvector INTERFACE
)

target_include_directories(libmyvector INTERFACE
       	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

add_library(libinertialdriver SHARED
	src/InertialDriver.cpp
	src/Misura.cpp
)

target_link_libraries(libinertialdriver PUBLIC libmyvector)

add_executable(main src/main.cpp)

target_link_libraries(main PRIVATE libinertialdriver)

