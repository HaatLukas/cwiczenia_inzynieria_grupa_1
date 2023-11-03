cmake_minimum_required(VERSION 3.26)
project(warcaby)

set(CMAKE_CXX_STANDARD 17)

add_executable(warcaby main.cpp
        core/timer.cpp
        core/timer.h
        core/engine.cpp
        core/engine.h
        core/player.cpp
        core/player.h
        core/board.cpp
        core/board.h
        core/pawn.cpp
        core/pawn.h)
