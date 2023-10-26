//
// Created by david on 26.10.2023.
//

#ifndef WARCABY_ENGINE_H
#define WARCABY_ENGINE_H

#include "timer.h"

namespace game {

    class Engine {
        Timer timer;

    public:
        Engine();
        void run();
    };

} // game

#endif //WARCABY_ENGINE_H
