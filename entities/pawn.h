//
// Created by david on 03.11.2023.
//

#ifndef WARCABY_PAWN_H
#define WARCABY_PAWN_H


#include "player.h"

namespace game {

    class Pawn {
        Player *owner;
        int color;
        bool selected;
        bool isQueen;

    public:
        explicit Pawn(Player *owner, int color) : color(color), isQueen(false), selected(false), owner(owner) {}

        [[nodiscard]] int getColor() const {
            return color;
        }

        void setSelected(bool val) {
            selected = val;
        }

        [[nodiscard]] Player *getOwner() const {
            return owner;
        }

        [[nodiscard]] bool isSelected() const {
            return selected;
        }

    };

} // game

#endif //WARCABY_PAWN_H
