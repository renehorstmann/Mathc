cmake_minimum_required(VERSION 3.0)
project(Mathc)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)


# check platform
if (MINGW)
    message("Platform: Windows MinGW")
    add_definitions(-DPLATFORM_MINGW)
    set(PLATFORM_MINGW true)
elseif(WIN32)
    message("Platform: Windows MSVC")
    add_definitions(-DPLATFORM_MSVC)
    set(PLATFORM_MSVC true)
else()
    message("Platform: UNIX")
    add_definitions(-DPLATFORM_UNIX)
    set(PLATFORM_UNIX true)
endif()

if(PLATFORM_MINGW OR PLATFORM_UNIX)
    message("Setup Unix || Windows MinGW")

    # warnings
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -pedantic")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-long-long -Wno-unused-function -Wno-unused-variable -Wno-missing-braces -Wno-unused-parameter")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-long-long -Wno-unused-function -Wno-unused-variable -Wno-missing-braces -Wno-unused-parameter -Wno-unused-but-set-variable")

    set(LINK_LIST m)

endif()

if(PLATFORM_MSVC)
    message("Setup Windows MSVC")

    # set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4 /WX")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /wd4267 /wd4244 /wd4305 /wd4996 /wd5105")

    set(LINK_LIST)
endif()


add_executable(main examples/main.c)
target_include_directories(main PUBLIC include)
target_link_libraries(main ${LINK_LIST})

add_executable(vector_type_usage examples/vector_type_usage.c)
target_include_directories(vector_type_usage PUBLIC include)
target_link_libraries(vector_type_usage ${LINK_LIST})

add_executable(vector_type_casting examples/vector_type_casting.c)
target_include_directories(vector_type_casting PUBLIC include)
target_link_libraries(vector_type_casting ${LINK_LIST})

add_executable(matrix_type examples/matrix_type.c)
target_include_directories(matrix_type PUBLIC include)
target_link_libraries(matrix_type ${LINK_LIST})

add_executable(typeless_functions examples/typeless_functions.c)
target_include_directories(typeless_functions PUBLIC include)
target_link_libraries(typeless_functions ${LINK_LIST})

add_executable(example examples/example.c)
target_include_directories(example PUBLIC include)
target_link_libraries(example ${LINK_LIST})

add_executable(cpp_test examples/cpp_test.cpp)
target_include_directories(cpp_test PUBLIC include)
target_link_libraries(cpp_test ${LINK_LIST})


add_library(performance_test_lib SHARED examples/performance_test_lib.c)
target_include_directories(performance_test_lib PUBLIC include)
target_link_libraries(performance_test_lib ${LINK_LIST})

add_executable(performance_test_call examples/performance_test_call.c)
target_include_directories(performance_test_call PUBLIC include)
target_link_libraries(performance_test_call ${LINK_LIST} performance_test_lib)
