cmake_minimum_required(VERSION 3.0)
project(Mathc)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -march=native)  # march=native for best performance
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic -Wno-unused-function")


add_executable(example examples/example.c)
target_include_directories(example PUBLIC include)
target_link_libraries(example m)

add_executable(vec examples/vec_example.c)
target_include_directories(vec PUBLIC include)
target_link_libraries(vec m)

add_executable(mat examples/mat_example.c)
target_include_directories(mat PUBLIC include)
target_link_libraries(mat m)

add_executable(quat examples/quat_example.c)
target_include_directories(quat PUBLIC include)
target_link_libraries(quat m)

add_executable(utils examples/utils_example.c)
target_include_directories(utils PUBLIC include)
target_link_libraries(utils m)

add_executable(cpp_test examples/cpp_test.cpp)
target_include_directories(cpp_test PUBLIC include)
target_link_libraries(cpp_test m)


add_library(performance_test_lib SHARED examples/performance_test_lib.c)
target_include_directories(performance_test_lib PUBLIC include)
target_link_libraries(performance_test_lib m)

add_executable(performance_test_call examples/performance_test_call.c)
target_include_directories(performance_test_call PUBLIC include)
target_link_libraries(performance_test_call m performance_test_lib)
