cmake_minimum_required(VERSION 3.16)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

project(team_result)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_SOURCE_FILES team_result.c)
add_library(team_result STATIC ${LIB_SOURCE_FILES})

add_executable(main main.c)
target_link_libraries(main team_result)

add_executable(test test.cpp)
target_link_libraries(test team_result gtest_main)