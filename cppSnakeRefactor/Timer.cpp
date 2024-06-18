//
// Created by jacob on 2024/6/17.
//
#include "Timer.h"
#include<iostream>

Timer::Timer() : running(false), interval(1000) {}

Timer::~Timer() {
    StopUpdating();
}

void Timer::StartUpdating() {
    std::cout<<"make new thread and start updating the mine"<<"\n";
}

void Timer::StopUpdating() {

}

void Timer::AddListener() {
}

void Timer::onTime() {

}


