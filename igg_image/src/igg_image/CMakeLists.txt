#################### Import the 'io_tools' library here ########################
add_library(io_tools io_tools.h io_tools.cpp)

#################### Create a library 'image' below this line ##################
add_library(image image.h image.cpp)


add_executable(main main.cpp)

target_link_libraries(main io_tools image)