cmake_minimum_required(VERSION 3.16)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

project(team_list)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_SOURCE_FILES team_list.c)
add_library(team_list STATIC ${LIB_SOURCE_FILES})

add_executable(main main.c)
target_link_libraries(main team_list)

add_executable(team_list_test team_list_test.cpp)
target_link_libraries(team_list_test team_list gtest_main)

# Build main
option(MAIN ON)
if (MAIN)
    add_executable(main main.c)
    target_link_libraries(main team_list)
endif()

# Build team_list_test
option(TEAM_LIST ON)
if (TEAM_LIST)
    enable_testing()
    include(GoogleTest)
    add_executable(team_list team_list.cpp)
    target_link_libraries(team_list_test team_list gtest_main)
    gtest_add_tests(TARGET team_list_test)
endif()