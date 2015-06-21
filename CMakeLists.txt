cmake_minimum_required(VERSION 3.0.4)

set(ProjectName "ProjectEuler" CACHE STRING "Project Name")
project(${ProjectName})

set(CMAKE_BUILD_TYPE "DEBUG")

set(CMAKE_INSTALL_PREFIX "install")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Og")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native" )

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -ggdb")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Og")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O2")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=native")

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "RELEASE")
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory("Exec")
add_subdirectory("Problems")
