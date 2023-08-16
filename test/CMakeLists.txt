cmake_minimum_required(VERSION 2.8)

set(CMAKE_MACOSX_RPATH 0)

project(sql-builder)

set(CMAKE_CXX_STANDARD 23)
set(DEBUG_FLAGS "-std=c++23 -g -O1 -Wall -Wextra -pedantic")
set(RELEASE_FLAGS "-std=c++23 -O3 -Wall -Wextra -pedantic")

set(CMAKE_CXX_FLAGS ${RELEASE_FLAGS})
set(CMAKE_CXX_FLAGS_DEBUG ${DEBUG_FLAGS})
set(CMAKE_CONFIGURATION_TYPES Debug Release)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})

include_directories(sql-test "../")

set(SQL_TEST_SRC            test.cpp)
set(INSERT_MODEL_TEST_SRC   insert_model_test.cpp)
set(SELECT_MODEL_TEST_SRC   select_model_test.cpp)
set(DELETE_MODEL_TEST_SRC   delete_model_test.cpp)
set(UPDATE_MODEL_TEST_SRC   update_model_test.cpp)

add_executable(sql-test ${SQL_TEST_SRC})
add_test(all "sql-test")

add_executable(insert-test ${INSERT_MODEL_TEST_SRC})
add_test(insert "insert-test")
add_executable(select-test ${SELECT_MODEL_TEST_SRC})
add_test(select "select-test")
add_executable(delete-test ${DELETE_MODEL_TEST_SRC})
add_test(delete "delete-test")
add_executable(update-test ${UPDATE_MODEL_TEST_SRC})
add_test(update "update-test")

enable_testing()
