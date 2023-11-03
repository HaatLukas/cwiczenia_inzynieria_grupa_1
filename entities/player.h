//
// Created by david on 03.11.2023.
//

#ifndef WARCABY_PLAYER_H
#define WARCABY_PLAYER_H

#include <utility>

#include "../core/timer.h"

namespace game {

    class Player {
        Timer timer;
        std::string name;

    public:
        Player() = default;

        explicit Player(std::string name) : name(std::move(name)) {};

        [[nodiscard]] Timer *getTimer() {
            return &timer;
        }

        [[nodiscard]] std::string getName() const {
            return name;
        }

    };

} // core

#endif //WARCABY_PLAYER_H
