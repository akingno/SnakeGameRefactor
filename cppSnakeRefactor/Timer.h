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
#include <memory>
#include <atomic>

class Timer {
public:

                                    Timer();
                                    ~Timer();
    void                            StartUpdating();
    void                            StopUpdating();
    void                            AddListener(std::shared_ptr<OnTimeListener> newListener);
    void                            onTime();


private:
    void                                            UpdateLoop();
    std::atomic<bool>                               isTimerRunning;
    int                                             interval;
    std::thread                                     timerThread;
    std::vector<std::shared_ptr<OnTimeListener>>    listeners;

};

#endif //CPPSNAKEREFACTOR_TIMER_H
