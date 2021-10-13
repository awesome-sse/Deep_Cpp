cmake_minimum_required(VERSION 3.16)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

project(team_list)

# This flags are used if cmake is called with -DCMAKE_BUILD_TYPE=PROFILE
set(CMAKE_C_FLAGS_PROFILE --coverage)
set(CMAKE_CXX_FLAGS_PROFILE --coverage)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set cpp compile flags
set(CPP_FLAGS)
set(C_FLAGS)
set(CMAKE_CXX_FLAGS ${CPP_FLAGS})
set(CMAKE_C_FLAGS ${C_FLAGS})

set(LIB_SOURCE_FILES team_list.c)
add_library(team_list STATIC ${LIB_SOURCE_FILES})

# Build main
add_executable(main main.c)
target_link_libraries(main team_list)

# Build team_list_test
enable_testing()

add_executable(team_list_test team_list_test.cpp)
target_link_libraries(team_list_test gtest_main team_list)

include(GoogleTest)
gtest_add_tests(TARGET team_list_test)