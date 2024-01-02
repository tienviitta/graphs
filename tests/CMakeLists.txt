add_executable(tests tests.cpp graphs_t.cpp)
target_link_libraries(tests PUBLIC graphs Catch2::Catch2)

# allow user to run tests with `make test` or `ctest`
catch_discover_tests(tests)
