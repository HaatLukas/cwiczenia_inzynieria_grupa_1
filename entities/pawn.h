//
// Created by david on 03.11.2023.
//

#ifndef WARCABY_PAWN_H
#define WARCABY_PAWN_H


namespace game {

    class Pawn {
        int color;
        bool isSelected;
        bool isQueen;

    public:
        explicit Pawn(int color = 0): color(color), isQueen(false), isSelected(false) {}

        [[nodiscard]] int getColor() const {
            return color;
        }

        void setColor(int newColor) {
            color = newColor;
        }

        void setSelected(bool selected){
            this->isSelected = selected;
        }

        [[nodiscard]] bool selectedValue() const
        {
            return isSelected;
        }

    };

} // game

#endif //WARCABY_PAWN_H
