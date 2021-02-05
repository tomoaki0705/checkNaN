# minimum requirement
cmake_minimum_required(VERSION 3.5)

# solution
project(checkNan)

# 3rd party variables
set(THIRD_PARTY_DIR "${CMAKE_BINARY_DIR}/third-party")
##  cache dir
set(CACHE_DIR "${CMAKE_SOURCE_DIR}/.cache")
file(MAKE_DIRECTORY ${CACHE_DIR})

# include gtest settings
include("cmake/gtest.cmake")

SET(TEST_NAME sampleTest)

# build TARGET_NAME from source code
cxx_test(${TEST_NAME} main.cpp )
target_include_directories(${TEST_NAME}   PUBLIC ${THIRD_PARTY_DIR}/include)

if(CMAKE_SYSTEM_PROCESSOR MATCHES "^(arm.*|ARM.*)")
    set(ARM 1)
endif()

if (ARM)
    message(STATUS "detected ARM architecture")
    set(CMAKE_CXX_FLAGS "-mfp16-format=ieee -mfpu=neon-fp16")
endif()

