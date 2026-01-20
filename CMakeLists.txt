cmake_minimum_required(VERSION 3.10)
project(c_ds_lib C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_library(ds
    src/list.c
    src/stack.c
    src/queue.c
)

target_include_directories(ds PUBLIC include)

enable_testing()

add_executable(test_list tests/test_list.c)
target_link_libraries(test_list ds)
add_test(NAME list_tests COMMAND test_list)

add_executable(test_stack tests/test_stack.c)
target_link_libraries(test_stack ds)
add_test(NAME stack_tests COMMAND test_stack)

add_executable(test_queue tests/test_queue.c)
target_link_libraries(test_queue ds)
add_test(NAME queue_tests COMMAND test_queue)

add_executable(test_list_generic tests/test_list_generic.c)
target_link_libraries(test_list generic ds)
