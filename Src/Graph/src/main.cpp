//
// Created by wyq on 18-7-26.
//

#include "graphAlgorithm.h"

int main(void)
{
    vector<pair<int, int> > prerequisites;
    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(2, 0));
    prerequisites.push_back(make_pair(3, 1));
    prerequisites.push_back(make_pair(3, 2));

    bool  result = canFinish2(4,prerequisites);
    printf("result = %d\n",result);
}