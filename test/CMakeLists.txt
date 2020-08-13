# Find gtest
find_package(GTest)

if(NOT GTest_FOUND)
    message(WARNING "Missing GTest... tests will not be generated.")
else()
    # Generate tests.
    include_directories(${GTEST_INCLUDE_DIRS})
    enable_testing()
    file(GLOB TEST_SRC ./*.cpp)
    add_executable(run_all ${TEST_SRC})
    target_link_libraries(run_all ${GTEST_BOTH_LIBRARIES})
    target_link_libraries(run_all template_lib)
endif()