cmake_minimum_required(VERSION 3.16)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

project(team_list)

# The libs above also need to be compiled with the same flags.
set_target_properties(dss-sim
PROPERTIES
COMPILE_FLAGS "-ftest-coverage -fprofile-arcs"LINK_FLAGS    "-lgcov --coverage")
#Set library
set(LIB_SOURCE_FILES team_list.c)
add_library(team_list STATIC ${LIB_SOURCE_FILES})

# Build main
add_executable(main main.c)
target_link_libraries(main team_list)

# Build team_list_test
enable_testing()

add_executable(team_list_test team_list_test.cpp)
target_link_libraries(team_list_test team_list gtest_main)

include(GoogleTest)
gtest_add_tests(TARGET team_list_test)