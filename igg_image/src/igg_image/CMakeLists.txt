#################### Import the 'io_tools' library here ########################


#################### Create a library 'image' below this line ##################
add_library(image image.h image.cpp)


add_executable(main main.cpp)

target_link_libraries(main ${PROJECT_SOURCE_DIR}/lib/libio_tools.so image)