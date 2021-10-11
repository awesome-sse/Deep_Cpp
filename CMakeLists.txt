project(team_result_list)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_SOURCE_FILES team_result.c)
add_library(team_result STATIC ${LIB_SOURCE_FILES})

add_executable(main main.c)
target_link_libraries(main team_result)