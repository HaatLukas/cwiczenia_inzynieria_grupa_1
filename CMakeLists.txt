cmake_minimum_required(VERSION 3.26)
project(warcaby)

set(CMAKE_CXX_STANDARD 17)

add_executable(warcaby main.cpp
        game/timer.cpp
        game/timer.h
        game/engine.cpp
        game/engine.h
        game/player.cpp
        game/player.h
        game/board.cpp
        game/board.h
        game/pawn.cpp
        game/pawn.h)
