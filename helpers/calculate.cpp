//
// Created by david on 06.11.2023.
//

#include <cmath>
#include "calculate.h"

namespace game {
    coordinates calcCoord(coordinates c, int size) {
        return {static_cast<int>(std::ceil((float) (c.x - size) / size)),
                static_cast<int>(std::ceil((float) (c.y - size) / size))};
    }
} // game