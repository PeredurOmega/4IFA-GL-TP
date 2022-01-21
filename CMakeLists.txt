cmake_minimum_required(VERSION 3.17)
project(TP_4IFA_GL)

set(CMAKE_CXX_STANDARD 14)


add_executable(TP_4IFA_GL main.cpp lexer.h lexer.cpp automaton.h automaton.cpp state.h state.cpp symbol.h symbol.cpp)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic -Werror)