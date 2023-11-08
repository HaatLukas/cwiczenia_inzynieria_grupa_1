#ifndef WARCABY_CALCULATE_H
#define WARCABY_CALCULATE_H

#include "../entities/board.h"

namespace game {

    coordinates calcCoord(coordinates c, float size);

    int calcPos(int size, float mul, int index);

} // game

#endif //WARCABY_CALCULATE_H
