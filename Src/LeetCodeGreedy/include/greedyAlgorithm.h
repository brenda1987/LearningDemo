//
// Created by wyq on 18-7-3.
//

#ifndef PROJECT_GREEDYALGORITHM_H
#define PROJECT_GREEDYALGORITHM_H

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

//1. leetcode 455, assign cookies
int findContentChildren(vector<int> &g,vector<int> &s);

//2. LeetCode 376,Wiggle Subsequence
int wiggleMaxLength(vector<int>& nums);

//3.LeetCode 402.Remove K Digits
string removeKdigits(string num, int k);

//4. LeetCode 55.Jump Game
bool canJump(vector<int>& nums);

//5. LeetCode 45.Jump Game II
int jump(vector<int>& nums);

//6, LeetCode 452.Minimum Number of Arrows to Burst Balloons
int findMinArrowShots(vector<pair<int, int> >& points);

//7. poj2431 Expedition
int get_minimum_stop(int L, int P, vector<pair<int, int> > &stop);

#endif //PROJECT_GREEDYALGORITHM_H
