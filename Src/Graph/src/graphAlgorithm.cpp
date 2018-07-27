//
// Created by wyq on 18-7-26.
//

#include <queue>
#include "graphAlgorithm.h"

//visit 表示节点状态，-1表示未访问，0表示正在访问，1表示访问结束
bool DFS_graph(GraphNode *node, vector<int> &visit)
{
    visit[node->lable] = 0;
    for (int i = 0; i < node->neighbors.size(); ++i) {
        if(visit[node->neighbors[i]->lable]==-1)
        {
            if ( DFS_graph(node->neighbors[i],visit)== 0)
                return false;
        }

        else if(visit[node->neighbors[i]->lable]==0)
            return false;
    }
    visit[node->lable] = 1;
    return true;
}

//LeetCode 207.Course Schedule(solve1)
bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites)
{
    vector<int> visit;
    vector<GraphNode*> graph;
    for (int i = 0; i < numCourses; ++i) {
        visit.push_back(-1);
        graph.push_back(new GraphNode(i));
    }
    for (int j = 0; j < prerequisites.size(); ++j) {
        GraphNode *begin = graph[prerequisites[j].second];
        GraphNode *end = graph[prerequisites[j].first];
        begin->neighbors.push_back(end);
    }
    for (int k = 0; k < graph.size(); ++k) {
        if(visit[k]==-1 && !DFS_graph(graph[k],visit))
            return false;
    }
    for (int l = 0; l < numCourses; ++l) {
        delete(graph[l]);
    }
    return true;
}

//LeetCode 207.Course Schedule(solve2)
bool canFinish2(int numCourses, vector<pair<int, int> >& prerequisites)
{
    vector<GraphNode*> graph;
    vector<int> degree;
    for (int i = 0; i < numCourses; ++i) {
        graph.push_back(new GraphNode(i));
        degree.push_back(0);
    }
    for (int j = 0; j < prerequisites.size(); ++j) {
        GraphNode* begin = graph[prerequisites[j].second];
        GraphNode* end = graph[prerequisites[j].first];
        begin->neighbors.push_back(end);
        degree[prerequisites[j].first]++;
    }
    queue<GraphNode*> Q;
    for (int k = 0; k < numCourses; ++k) {
        if(degree[k]==0)
            Q.push(graph[k]);
    }
    while (!Q.empty())
    {
        GraphNode *node = Q.front();
        Q.pop();
        for (int i = 0; i < node->neighbors.size(); ++i) {
            degree[node->neighbors[i]->lable]--;
            if (degree[node->neighbors[i]->lable]==0)
                Q.push(node->neighbors[i]);

        }
    }
    for (int l = 0; l < graph.size(); ++l) {
        delete(graph[l]);
    }
    for (int m = 0; m < degree.size(); ++m) {
        if(degree[m])
            return false;
    }
    return true;
}

