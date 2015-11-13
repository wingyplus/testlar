cmake_minimum_required(VERSION 3.0)
project(testlar)

include(CTest)

enable_testing()

set(TEST_DIR ${PROJECT_SOURCE_DIR}/test/testlar)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src/testlar)

include_directories(include)

add_library(testlar ${SRC_DIR}/testing)

add_executable(t_error_test ${TEST_DIR}/t_error_test)
target_link_libraries(t_error_test testlar)
add_executable(t_errorf_test ${TEST_DIR}/t_errorf_test)
target_link_libraries(t_errorf_test testlar)
add_executable(runner_test ${TEST_DIR}/runner_test)
target_link_libraries(runner_test testlar)

add_test(t_error_test t_error_test)
add_test(t_errorf_test t_errorf_test)
add_test(runner_test runner_test)
