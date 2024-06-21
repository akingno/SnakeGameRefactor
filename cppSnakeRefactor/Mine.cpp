//
// Created by jacob on 2024/6/17.
//
#include "Mine.h"
using namespace std;

void Mine::RefreshMine() {
    cout<<"Mine:Refresh Mine"<<"\n";
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribWeight(0,(Globals::GRAPH_WEIGHT - Globals::BLOCK_SIZE) / Globals::BLOCK_SIZE);
    uniform_int_distribution<> distribHeight(0,(Globals::GRAPH_HEIGHT - Globals::BLOCK_SIZE) / Globals::BLOCK_SIZE);

    pr_location.first   =   distribWeight(gen) * Globals::BLOCK_SIZE;
    pr_location.second  =   distribHeight(gen) * Globals::BLOCK_SIZE;
    cout << "Mine Location" << pr_location.first << ","<<pr_location.second<<endl;

}

Mine::Mine() = default;


void Mine::Draw() {
    setfillcolor(BLUE);
    solidcircle(pr_location.first + Globals::BLOCK_SIZE_HALF,
                pr_location.second + Globals::BLOCK_SIZE_HALF,
                Globals::BLOCK_SIZE_HALF);
}

std::pair<int, int> &Mine::GetLocation() {
    return pr_location;
}
