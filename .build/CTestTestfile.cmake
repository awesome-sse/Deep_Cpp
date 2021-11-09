# CMake generated Testfile for 
# Source directory: /app/C++/hm2/technopark_homeworks
# Build directory: /app/C++/hm2/technopark_homeworks/.build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEAM_LIST_TEST.test_clear_list "/app/C++/hm2/technopark_homeworks/.build/file_info_test" "--gtest_filter=TEAM_LIST_TEST.test_clear_list")
set_tests_properties(TEAM_LIST_TEST.test_clear_list PROPERTIES  _BACKTRACE_TRIPLES "/usr/share/cmake-3.16/Modules/GoogleTest.cmake;353;add_test;/app/C++/hm2/technopark_homeworks/CMakeLists.txt;34;gtest_add_tests;/app/C++/hm2/technopark_homeworks/CMakeLists.txt;0;")
add_test(TEAM_LIST_TEST.test_creating_file_info "/app/C++/hm2/technopark_homeworks/.build/file_info_test" "--gtest_filter=TEAM_LIST_TEST.test_creating_file_info")
set_tests_properties(TEAM_LIST_TEST.test_creating_file_info PROPERTIES  _BACKTRACE_TRIPLES "/usr/share/cmake-3.16/Modules/GoogleTest.cmake;353;add_test;/app/C++/hm2/technopark_homeworks/CMakeLists.txt;34;gtest_add_tests;/app/C++/hm2/technopark_homeworks/CMakeLists.txt;0;")
add_test(TEAM_LIST_TEST.test_lib_file_data_consistent "/app/C++/hm2/technopark_homeworks/.build/file_info_test" "--gtest_filter=TEAM_LIST_TEST.test_lib_file_data_consistent")
set_tests_properties(TEAM_LIST_TEST.test_lib_file_data_consistent PROPERTIES  _BACKTRACE_TRIPLES "/usr/share/cmake-3.16/Modules/GoogleTest.cmake;353;add_test;/app/C++/hm2/technopark_homeworks/CMakeLists.txt;34;gtest_add_tests;/app/C++/hm2/technopark_homeworks/CMakeLists.txt;0;")
add_test(TEAM_LIST_TEST.test_lib_file_data_parallel "/app/C++/hm2/technopark_homeworks/.build/file_info_test" "--gtest_filter=TEAM_LIST_TEST.test_lib_file_data_parallel")
set_tests_properties(TEAM_LIST_TEST.test_lib_file_data_parallel PROPERTIES  _BACKTRACE_TRIPLES "/usr/share/cmake-3.16/Modules/GoogleTest.cmake;353;add_test;/app/C++/hm2/technopark_homeworks/CMakeLists.txt;34;gtest_add_tests;/app/C++/hm2/technopark_homeworks/CMakeLists.txt;0;")
add_test(TEAM_LIST_TEST.test_increase_buf_size "/app/C++/hm2/technopark_homeworks/.build/file_info_test" "--gtest_filter=TEAM_LIST_TEST.test_increase_buf_size")
set_tests_properties(TEAM_LIST_TEST.test_increase_buf_size PROPERTIES  _BACKTRACE_TRIPLES "/usr/share/cmake-3.16/Modules/GoogleTest.cmake;353;add_test;/app/C++/hm2/technopark_homeworks/CMakeLists.txt;34;gtest_add_tests;/app/C++/hm2/technopark_homeworks/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
