cmake_minimum_required(VERSION 3.16.3)

project(test)


add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(external/glfw)
add_subdirectory(adder)

target_include_directories(${PROJECT_NAME} 
    PUBLIC adder 
    PUBLIC external/glfw/include
    
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE adder
    PRICATE external/glfw/src    
)

target_link_libraries(${PROJECT_NAME} adder glfw) 