cmake_minimum_required(VERSION 3.15)
project(DailyCodingProblem CXX)

enable_testing()
include(GoogleTest)

include_directories(Common)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "Easy/*.cpp" "Medium/*.cpp" "Hard/*.cpp")
add_executable(problems ${SOURCES})
target_link_libraries(problems gtest gtest_main pthread)
gtest_discover_tests(problems)
set_target_properties(problems PROPERTIES COMPILE_FLAGS "-Wall -Wextra -Wpedantic -Werror")
add_test(NAME problems COMMAND problems)

add_custom_target(tests ALL COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure --progress)
