cmake_minimum_required(VERSION 3.26)
project(warcaby)

set(CMAKE_CXX_STANDARD 17)

add_executable(warcaby main.cpp
        core/timer.cpp
        core/timer.h
        core/engine.cpp
        core/engine.h
        entities/player.cpp
        entities/player.h
        entities/board.cpp
        entities/board.h
        entities/pawn.cpp
        entities/pawn.h)
