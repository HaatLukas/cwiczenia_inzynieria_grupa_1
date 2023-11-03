//
// Created by david on 03.11.2023.
//

#include "pawn.h"

namespace game {

    void Pawn::setColor(int newColor)
    {
        this->color = newColor;
    }

    int Pawn::getColor()
    {
        return this->color;
    }
} // core