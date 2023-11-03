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

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/Libraries/SFML-2.6.0/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio REQUIRED)

include_directories(C:/Libraries/SFML-2.6.0/include)
target_link_libraries(warcaby sfml-system sfml-window sfml-graphics sfml-audio)