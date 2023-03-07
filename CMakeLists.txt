cmake_minimum_required(VERSION 3.20)
project(LeetCode CXX)

# download GoogleTest from the internet
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
FetchContent_MakeAvailable(googletest)

# enable GoogleTest
include(GoogleTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)

function(defineTest)
cmake_parse_arguments(
  PARSED_ARGS     # prefix of output variables
  ""              # list of names of boolean arguments (only defined ones will be true)
  "TESTNAME"      # list of names of mono-valued arguments
  "SOURCES;LIBS"  # list of names of multi-valued arguments (output variables are lists)
  ${ARGN}         # arguments of the function to parse
  )
  add_executable(${PARSED_ARGS_TESTNAME} ${PARSED_ARGS_SOURCES})
  target_link_libraries(${PARSED_ARGS_TESTNAME} ${PARSED_ARGS_LIBS} gtest gtest_main)
  set_target_properties(${PARSED_ARGS_TESTNAME} PROPERTIES COMPILE_FLAGS "-Wall -Wextra -Wpedantic -Werror")
endfunction()

file(GLOB EASY_SOURCES   "Easy/*.cpp")
file(GLOB MEDIUM_SOURCES "Medium/*.cpp")
#file(GLOB HARD_SOURCES   "Hard/*.cpp")

defineTest(TESTNAME TestEasy   SOURCES ${EASY_SOURCES})
defineTest(TESTNAME TestMedium SOURCES ${MEDIUM_SOURCES})
#defineTest(TESTNAME TestHard   SOURCES ${HARD_SOURCES})
