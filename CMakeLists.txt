cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 11)

# set the project name
project(tictactoe3)

# you can add more once we have more than one source file, just put a space
set(SOURCES "$tictactoe3.cpp")

set(TICTACTOE3_TESTS "tictactoe3_Test.cpp")

add_executable(TICTACTOE3_tests ${TICTACTOE3_TESTS} "tictactoe3.cpp")