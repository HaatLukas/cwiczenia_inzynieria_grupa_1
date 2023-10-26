//
// Created by david on 26.10.2023.
//

#include <thread>
#include "timer.h"

namespace game {
    void Timer::setInterval(const std::function<void()> &fc, int interval) {
        active = true;
        std::thread t([=]() {
            while (active.load()) {
                std::this_thread::sleep_for(std::chrono::milliseconds(interval));
                if (!active.load()) return;
                fc();
            }
        });
        t.detach();
    }
} // game