cmake_minimum_required(VERSION 3.0)
project(Mathc)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -march=native)  # march=native for best performance
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic -Wno-unused-function")

add_executable(vecmath examples/vecmath_example.c)
target_include_directories(vecmath PUBLIC include)
target_link_libraries(vecmath m)

add_executable(matmath examples/matmath_example.c)
target_include_directories(matmath PUBLIC include)
target_link_libraries(matmath m)


add_executable(vec examples/vec_example.c)
target_include_directories(vec PUBLIC include)
target_link_libraries(vec m)

add_executable(mat examples/mat_example.c)
target_include_directories(mat PUBLIC include)
target_link_libraries(mat m)



add_library(performance_test_lib SHARED examples/performance_test_lib.c)
target_include_directories(performance_test_lib PUBLIC include)
target_link_libraries(performance_test_lib m)

add_executable(performance_test_call examples/performance_test_call.c)
target_include_directories(performance_test_call PUBLIC include)
target_link_libraries(performance_test_call m performance_test_lib)
