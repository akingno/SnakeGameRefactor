//
// Created by jacob on 2024/6/17.
//

#include "Fruit.h"

Fruit::Fruit(const std::pair<int, int> pr_location)
    : pr_location(pr_location) {}

std::pair<int, int> &Fruit::GetLocation() { return pr_location; }
Fruit::~-mFruit() = default;
