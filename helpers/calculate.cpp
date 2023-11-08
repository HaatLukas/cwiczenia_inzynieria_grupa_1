#include <cmath>
#include "calculate.h"

namespace game {
    coordinates calcCoord(coordinates c, float size) {
        return { static_cast<int>((c.x - size) / size),
                 static_cast<int>((c.y - size) / size)};
    }
} // game
