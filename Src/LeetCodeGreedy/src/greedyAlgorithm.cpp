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
string removeKdigits(string num, int k)
{
    vector<int> S;
    string result = "";
    for (int i = 0; i < num.size(); ++i) {
        int number = num[i]-'0';
        while (k>0 && !S.empty() && number< S.back() )
        {
            S.pop_back();
            k--;
        }
        if(number!=0 || !S.empty())
            S.push_back(number);
    }
    while (k>0 && !S.empty())
    {
        S.pop_back();
        k--;
    }
    for (int j = 0; j < S.size(); ++j) {
        result.append(1,S[j]+'0');
    }
    if(result=="")
        result = "0";
    return result;
}


//4. LeetCode 55.Jump Game
bool canJump(vector<int>& nums)
{
    vector<int> index;
    for (int i = 0; i < nums.size(); ++i) {
        index.push_back(nums[i]+i);
    }
    int jump = 0;
    int max_index = index[0];
    while (jump<index.size() && jump<=max_index) {
        if(max_index<index[jump])
            max_index = index[jump];
        jump++;
    }
    if(jump==nums.size())
    {
        return true;
    }
    return false;
}