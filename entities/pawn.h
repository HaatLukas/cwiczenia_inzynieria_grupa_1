//
// Created by david on 03.11.2023.
//

#ifndef WARCABY_PAWN_H
#define WARCABY_PAWN_H


namespace game {

    class Pawn {
        int color;
        bool isQueen = false;

    public:
        explicit Pawn(int color = 0): color(color) {}

        [[nodiscard]] int getColor() const {
            return color;
        }

        void setColor(int newColor) {
            color = newColor;
        }

    };

} // game

#endif //WARCABY_PAWN_H
