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
                if (paused.load()) continue;
                std::this_thread::sleep_for(std::chrono::milliseconds(interval));
                if (!active.load()) return;
                fc();
            }
        });
        t.detach();
    }

    void Timer::init() {
        setInterval([=]() {
            value--;

            if (value.load() <= 0) {
                active = false;
                value = 0;
            }
        }, 1000);
    }

    void Timer::stop() {
        paused = true;
    }

    void Timer::resume() {
        paused = false;
    }
} // game