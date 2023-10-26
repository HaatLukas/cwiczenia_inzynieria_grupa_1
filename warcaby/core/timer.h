//
// Created by david on 26.10.2023.
//

#ifndef WARCABY_TIMER_H
#define WARCABY_TIMER_H

#include <functional>
#include <atomic>

namespace game {

    class Timer {
        std::atomic<bool> active{true};
        std::atomic<int> value{0};
        void setInterval(const std::function<void()>& fc, int interval);

    public:
        void setValue(const int &startValue) {
            value = startValue;
        }
        void run() {
            setInterval([&](){
                value--;
            },  1000);
        }
    };

} // game

#endif //WARCABY_TIMER_H
