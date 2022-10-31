cmake_minimum_required(VERSION 3.23)
project(PokerHand)

set(CMAKE_CXX_STANDARD 14)

add_executable(PokerHand main.cpp PokerHand.hpp Card.hpp 52Cards.hpp)
