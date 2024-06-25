//
// Created by jacob on 2024/6/17.
//
#include "Timer.h"
#include <iostream>

Timer::Timer() : isTimerRunning(false), interval(1000) {}

Timer::~Timer() { StopUpdating(); }

void Timer::StartUpdating() {
  std::cout << "Timer:StartUpdating"
            << "\n";
  isTimerRunning.store(true);
  timerThread = std::thread(&Timer::UpdateLoop, this);
  std::cout << "Timer:StartedUpdating"
            << "\n";
}

void Timer::StopUpdating() {

  isTimerRunning.store(false);
  // TODO:此处这个join会导致结束时卡顿
  if (timerThread.joinable()) {
    timerThread.join();
  }
  std::cout << "Timer:StoppedUpdating"
            << "\n";
}

void Timer::AddListener(std::shared_ptr<OnTimeListener> newListener) {
  listeners.push_back(newListener);
}

void Timer::onTime() {
  if (isTimerRunning.load()) { // Double-check to avoid unnecessary update calls
    for (const auto &listener : listeners) {
      listener->Notified();
    }
  }
}

void Timer::UpdateLoop() {
  while (isTimerRunning.load()) {
    std::this_thread::sleep_for(std::chrono::seconds(10));
    onTime();
  }
}

void Timer::clearListenner() { listeners.clear(); }
