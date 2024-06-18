//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_TIMER_H
#define CPPSNAKEREFACTOR_TIMER_H

#include <vector>
#include <functional>
#include <thread>
#include <chrono>
#include "OnTimeListener.h"
class Timer {
public:

                                    Timer();
                                    ~Timer();
    void                            StartUpdating();
    void                            StopUpdating();
    void                            AddListener();
    void                            onTime();


private:

    bool                            running;
    int                             interval;
    std::thread                     timerThread;
    std::vector<onTimeListener*>    listeners;
};

#endif //CPPSNAKEREFACTOR_TIMER_H
