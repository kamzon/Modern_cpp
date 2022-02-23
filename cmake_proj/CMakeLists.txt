project(cmake_test_project)
cmake_minimum_required(VERSION 3.0)

message(STATUS "!!!!!!!!!!!!!!!!!!!1${PROJECT_SOURCE_DIR}")

include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)






