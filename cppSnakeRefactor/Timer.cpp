//
// Created by jacob on 2024/6/17.
//
#include "Timer.h"

Timer::Timer() : running(false), interval(1000) {}

Timer::~Timer() {
    StopUpdating();
}

void Timer::StartUpdating() {
}

void Timer::StopUpdating() {

}

void Timer::AddListener() {
}


