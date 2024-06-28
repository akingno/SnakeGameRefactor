//
// Created by jacob on 2024/6/17.
//

#ifndef CPPSNAKEREFACTOR_TIMER_H
#define CPPSNAKEREFACTOR_TIMER_H

#include "OnTimeListener.h"
#include <atomic>
#include <chrono>
#include <functional>
#include <memory>
#include <thread>
#include <vector>

class Timer {
public:
  Timer();
  ~Timer();

  void StartUpdating();
  void StopUpdating();

  void AddListener(std::shared_ptr<OnTimeListener> newListener);
  void clearListenner();

private:
  void UpdateLoop();
  void onTime();
private:
  std::atomic<bool>                             isTimerRunning;
  std::thread                                   timerThread;
  std::vector<std::shared_ptr<OnTimeListener>>  listeners;
};

#endif // CPPSNAKEREFACTOR_TIMER_H
