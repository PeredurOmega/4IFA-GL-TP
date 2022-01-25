cmake_minimum_required(VERSION 3.17)
project(TP_4IFA_GL)

set(CMAKE_CXX_STANDARD 14)
set(-ansi -pedantic -Wall)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

add_executable(TP_4IFA_GL main.cpp lexer.h lexer.cpp automaton.h automaton.cpp state.h state.cpp symbols.h symbols.cpp)
