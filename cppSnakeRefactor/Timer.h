//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_TIMER_H
#define CPPSNAKEREFACTOR_TIMER_H

#include <vector>
#include <functional>
#include <thread>
#include <chrono>

class Timer {
public:
    class onTimeListener {
    public:
        virtual void onTimer() = 0;
    };

    Timer();
    ~Timer();
    void start();
    void stop();
    void addListener();

private:
    void notify();
    bool running;
    int interval;
    std::thread timerThread;
    std::vector<onTimeListener*> listeners;
};

#endif //CPPSNAKEREFACTOR_TIMER_H
