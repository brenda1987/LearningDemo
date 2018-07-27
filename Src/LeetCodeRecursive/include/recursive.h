//
// Created by wyq on 18-7-5.
//

#ifndef PROJECT_RECURSIVE_H
#define PROJECT_RECURSIVE_H

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

//1.leetcode 78, Subsets,方法1，回溯法
vector<vector<int> > subsets1(vector<int> &nums);

//2.leetcode 78, Subsets,方法2，位运算法
vector<vector<int> > subsets2(vector<int> &nums);

//3.leetcode 90, SubsetsII
vector<vector<int> > subsetsWithDup(vector<int> &nums);

//4.leetcode 40, Combination Sum II
vector<vector<int> > combinationSum2(vector<int>&candidates,int target);

//5.leetcode 22, Generate Parentheses
vector<string> generateParenthesis(int n);

//6.LeetCode 51. N-Queens
vector<vector<string> > solveNQueens(int n);

#endif //PROJECT_RECURSIVE_H
