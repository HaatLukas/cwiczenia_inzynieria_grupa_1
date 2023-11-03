//
// Created by david on 03.11.2023.
//

#ifndef WARCABY_PAWN_H
#define WARCABY_PAWN_H


namespace game {

    class Pawn{

        int color;
        bool isQueen = false;
    public:
        int getColor();
        void setColor(int newColor);

    };

} // core

#endif //WARCABY_PAWN_H
