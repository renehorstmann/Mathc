cmake_minimum_required(VERSION 3.0)
project(Mathc)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

# warnings
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -pedantic")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-long-long -Wno-unused-function -Wno-unused-variable -Wno-missing-braces -Wno-unused-parameter")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-long-long -Wno-unused-function -Wno-unused-variable -Wno-missing-braces -Wno-unused-parameter -Wno-unused-but-set-variable")


if (MINGW)
    add_definitions(-DMATHC_NO_PRINT_COLOR)
endif()


add_executable(main examples/main.c)
target_include_directories(main PUBLIC include)
target_link_libraries(main m)

add_executable(vector_type_usage examples/vector_type_usage.c)
target_include_directories(vector_type_usage PUBLIC include)
target_link_libraries(vector_type_usage m)

add_executable(vector_type_casting examples/vector_type_casting.c)
target_include_directories(vector_type_casting PUBLIC include)
target_link_libraries(vector_type_casting m)

add_executable(matrix_type examples/matrix_type.c)
target_include_directories(matrix_type PUBLIC include)
target_link_libraries(matrix_type m)

add_executable(typeless_functions examples/typeless_functions.c)
target_include_directories(typeless_functions PUBLIC include)
target_link_libraries(typeless_functions m)

add_executable(example examples/example.c)
target_include_directories(example PUBLIC include)
target_link_libraries(example m)

add_executable(cpp_test examples/cpp_test.cpp)
target_include_directories(cpp_test PUBLIC include)
target_link_libraries(cpp_test m)


add_library(performance_test_lib SHARED examples/performance_test_lib.c)
target_include_directories(performance_test_lib PUBLIC include)
target_link_libraries(performance_test_lib m)

add_executable(performance_test_call examples/performance_test_call.c)
target_include_directories(performance_test_call PUBLIC include)
target_link_libraries(performance_test_call m performance_test_lib)
