cmake_minimum_required(VERSION 3.20)
project(EncodedCPP)

set(CMAKE_CXX_STANDARD 14)

add_executable(EncodedCPP
        main.cpp classes/alphabet.hpp classes/alphabet.cpp classes/alphabet.hpp classes/codeLegendStorage.cpp classes/codeLegendStorage.hpp)