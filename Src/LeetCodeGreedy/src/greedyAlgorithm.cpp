//
// Created by wyq on 18-7-3.
//

#include "greedyAlgorithm.h"

//1. assign cookies,leetcode 455
int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int child = 0;
    int cookies = 0;
    while (child < g.size() && cookies < s.size()) {
        if (s[cookies] >= g[child]) {
            child++;
        }
        cookies++;
    }
    return child;
}

//2. LeetCode 376,Wiggle Subsequence
int wiggleMaxLength(vector<int> &nums) {
    if (nums.size() < 2)
        return nums.size();
    static const int BEGIN = 0;
    static const int UP = 1;
    static const int DOWN = 2;
    int STATE = BEGIN;
    int max_length = 1;
    for (int i = 1; i < nums.size(); ++i) {
        switch (STATE) {
            case BEGIN:
                if (nums[i] > nums[i - 1]) {
                    STATE = UP;
                    max_length++;
                } else if (nums[i] < nums[i - 1]) {
                    STATE = DOWN;
                    max_length++;
                }
                break;

            case UP:
                if (nums[i] < nums[i - 1]) {
                    STATE = DOWN;
                    max_length++;
                }
                break;

            case DOWN:
                if (nums[i] > nums[i - 1]) {
                    STATE = UP;
                    max_length++;
                }
                break;
        }

    }
    return max_length;
}

//3.LeetCode 402.Remove K Digits
string removeKdigits(string num, int k) {
    vector<int> S;
    string result = "";
    for (int i = 0; i < num.size(); ++i) {
        int number = num[i] - '0';
        while (k > 0 && !S.empty() && number < S.back()) {
            S.pop_back();
            k--;
        }
        if (number != 0 || !S.empty())
            S.push_back(number);
    }
    while (k > 0 && !S.empty()) {
        S.pop_back();
        k--;
    }
    for (int j = 0; j < S.size(); ++j) {
        result.append(1, S[j] + '0');
    }
    if (result == "")
        result = "0";
    return result;
}


//4. LeetCode 55.Jump Game
bool canJump(vector<int> &nums) {
    vector<int> index;
    for (int i = 0; i < nums.size(); ++i) {
        index.push_back(nums[i] + i);
    }
    int jump = 0;
    int max_index = index[0];
    while (jump < index.size() && jump <= max_index) {
        if (max_index < index[jump])
            max_index = index[jump];
        jump++;
    }
    if (jump == nums.size()) {
        return true;
    }
    return false;
}

//5. LeetCode 45.Jump Game II
int jump(vector<int> &nums) {
    if(nums.size()<2)
        return 0;
    int jump_min = 1;
    int cur_max_index = nums[0];
    int pre_max_index = nums[0];
    for (int i = 0; i < nums.size(); ++i) {
        if (i > cur_max_index) {
            jump_min++;
            cur_max_index = pre_max_index;
        }
        if (pre_max_index < (nums[i] + i))
            pre_max_index = nums[i] + i;
    }
    return jump_min;

}

//6, LeetCode 452.Minimum Number of Arrows to Burst Balloons
bool bmp(const pair<int, int>&a,const pair<int, int>&b)
{
    return a.first < b.first;
}

int findMinArrowShots(vector<pair<int, int> >& points)
{
    if(points.size()==0)
        return 0;
    sort(points.begin(),points.end(),bmp);
    int start = points[0].first;
    int end = points[0].second;
    int num = 1;
    for (int i = 1; i < points.size(); ++i) {
        if(points[i].first > end)
        {
            num++;
            start = points[i].first;
            end = points[i].second;
        } else
        {
            if(points[i].second < end)
                end = points[i].second;
        }

    }
    return num;
}


//7. poj2431 Expedition
bool cmp(const pair<int, int>&a,const pair<int, int>&b)
{
    return a.first > b.first;
}

int get_minimum_stop(int L, int P, vector<pair<int, int> > &stop)
{
    priority_queue<int> Q;  //存储汽油的最大堆
    int result = 0;  //记录加过几次油
    stop.push_back(make_pair(0,0));//将终点作为一个停靠点
    sort(stop.begin(),stop.end(),cmp);
    for (int i = 0; i < stop.size(); ++i) {
        int dis = L-stop[i].first;
        while (!Q.empty()&&P<dis)
        {
            result++;
            P += Q.top();
            Q.pop();
        }

        if(Q.empty() && P<dis)
        {
            return -1;

        }
        P = P-dis;
        L = stop[i].first;
        Q.push(stop[i].second);
    }
    return result;
}