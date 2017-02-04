cmake_minimum_required(VERSION 3.2)

project (test_project C CXX)

# compiler flags
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall" )
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0 -pg")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG -march=native")

option(CPU_ONLY "Build program without GPU support" OFF)
option(USE_OPENCV "Build with OpenCV support" ON)
option(USE_LEVELDB "Build with levelDB" OFF)
option(USE_LMDB "Build with lmdb" OFF)

# Path used for searching by FIND_XXX()
set(CMAKE_PREFIX_PATH "/usr/local/opt/opencv3/")

# sources
set (SRCS )
list (APPEND SRCS "./src/main.cpp")

# caffe
set (Caffe_INCLUDE_DIR )
list (APPEND Caffe_INCLUDE_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/caffe/include/")
list (APPEND Caffe_INCLUDE_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/caffe/build/src/")
set (Caffe_LIBS
    "${CMAKE_CURRENT_SOURCE_DIR}/caffe/build/lib/libcaffe.a")

# caffe's dependent libraries
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)
include(ExternalProject)
include (cmake/Utils.cmake)
include (cmake/Dependencies.cmake)

# include files
configure_file("src/config.hpp.in"
    "${CMAKE_CURRENT_BINARY_DIR}/config.hpp")
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${Caffe_INCLUDE_DIR})

# target application
add_executable(main ${SRCS})
target_link_libraries(main ${Caffe_LIBS} ${Caffe_LINKER_LIBS})

message(STATUS "CXX_FLAGS=${CMAKE_CXX_FLAGS}")
message(STATUS "CPU_ONLY=${CPU_ONLY}")
message(STATUS "USE_LEVELDB=${USE_LEVELDB}")
message(STATUS "USE_LMDB=${USE_LMDB}")
message(STATUS "BUILD_TYPE=${CMAKE_BUILD_TYPE}")
message(STATUS "Caffe_LIBS=${Caffe_LIBS}")
message(STATUS "Caffe_LINKER_LIBS=${Caffe_LINKER_LIBS}")
