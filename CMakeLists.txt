cmake_minimum_required(VERSION 3.16)

project(hm2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS_PROFILE --coverage)
set(CMAKE_CXX_FLAGS_PROFILE --coverage)

add_library(generate_files STATIC generate_files.c)
add_library(lib_file_data_consistent STATIC lib_file_data_consistent.c)
add_library(lib_file_data_parallel SHARED lib_file_data_parallel.c)
add_library(tools STATIC tools.c)
add_library(f_timer STATIC f_timer.c)

add_executable(main main.c)
target_link_libraries(main generate_files lib_file_data_consistent lib_file_data_parallel tools f_timer gtest_main)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(file_info_test file_info_test.cpp)
target_link_libraries(file_info_test tools lib_file_data_consistent lib_file_data_parallel gtest_main)

include(GoogleTest)
gtest_add_tests(TARGET file_info_test)