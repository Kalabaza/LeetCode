cmake_minimum_required(VERSION 3.20)
project(LeetCode CXX)

if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

# download GoogleTest from the internet
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  GIT_SHALLOW TRUE
)

set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

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
  target_include_directories(${PARSED_ARGS_TESTNAME} PRIVATE Common)
  target_link_libraries(${PARSED_ARGS_TESTNAME} ${PARSED_ARGS_LIBS} gtest gtest_main)
  target_compile_options(${PARSED_ARGS_TESTNAME} PRIVATE $<$<PLATFORM_ID:Windows>:/W4>
                                                         $<$<PLATFORM_ID:Linux>:-Wall -Wextra -Wpedantic -Werror>)
endfunction()

file(GLOB EASY_SOURCES   "Easy/*.cpp")
file(GLOB MEDIUM_SOURCES "Medium/*.cpp")
file(GLOB HARD_SOURCES   "Hard/*.cpp")

defineTest(TESTNAME TestEasy   SOURCES ${EASY_SOURCES})
defineTest(TESTNAME TestMedium SOURCES ${MEDIUM_SOURCES})
defineTest(TESTNAME TestHard   SOURCES ${HARD_SOURCES})
