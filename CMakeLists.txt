project(hm2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(generate_files STATIC generate_files.c)
add_library(file_info STATIC file_info.c)

set(CMAKE_C_FLAGS_PROFILE --coverage)
set(CMAKE_CXX_FLAGS_PROFILE --coverage)

add_executable(main main.c)
target_link_libraries(main generate_files file_info)