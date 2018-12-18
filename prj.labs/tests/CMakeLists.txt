add_executable(complex_test complex_test.cpp)
target_link_libraries(complex_test complex)
set_property(TARGET complex_test PROPERTY CXX_STANDARD 14)

add_executable(rational_test rational_test.cpp)
target_link_libraries(rational_test rational)
set_property(TARGET rational_test PROPERTY CXX_STANDARD 14)

add_executable(dynamical_array_test dynamical_array_test.cpp)
target_link_libraries(dynamical_array_test dynamical_array)
set_property(TARGET dynamical_array_test PROPERTY CXX_STANDARD 14)

add_executable(matrix_test matrix_test.cpp)
target_link_libraries(matrix_test matrix)
set_property(TARGET matrix_test PROPERTY CXX_STANDARD 14)

add_executable(queue_on_array_test queue_on_array_test.cpp)
target_link_libraries(queue_on_array_test queue_on_array)
set_property(TARGET queue_on_array_test PROPERTY CXX_STANDARD 14)

add_executable(stack_on_list_test stack_on_list_test.cpp)
target_link_libraries(stack_on_list_test stack_on_list)
set_property(TARGET stack_on_list_test PROPERTY CXX_STANDARD 14)
