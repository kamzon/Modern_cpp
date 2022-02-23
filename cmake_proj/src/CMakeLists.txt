
add_library(hello hello.cpp)
add_library(blah blah.cpp)

add_executable(main main.cpp)

target_link_libraries(main hello blah)

