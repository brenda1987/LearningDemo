//
// Created by wyq on 18-7-26.
//

#ifndef PROJECT_GRAPHALGORITHM_H
#define PROJECT_GRAPHALGORITHM_H

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct GraphNode{
    int lable;
    vector<GraphNode*> neighbors;
    GraphNode(int x):lable(x) {};
};

//LeetCode 207.Course Schedule(solve1)
bool DFS_graph(GraphNode *node, vector<int> &visit);  //图深度优先搜索
bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites);

//LeetCode 207.Course Schedule(solve2)
bool canFinish2(int numCourses, vector<pair<int, int> >& prerequisites);




#endif //PROJECT_GRAPHALGORITHM_H
