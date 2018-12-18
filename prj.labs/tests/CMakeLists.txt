add_executable(complex_test complex_test.cpp)
target_link_libraries(complex_test complex)
set_property(TARGET complex_test PROPERTY CXX_STANDARD 14)

add_executable(rational_test complex_test.cpp)
target_link_libraries(complex_test complex)
set_property(TARGET complex_test PROPERTY CXX_STANDARD 14)