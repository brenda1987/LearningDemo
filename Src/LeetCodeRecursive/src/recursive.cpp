//
// Created by wyq on 18-7-5.
//

#include "recursive.h"

//1.leetcode 78, Subsets,方法1，回溯法
void generate(int i, vector<int> &nums, vector<int> &items, vector<vector<int> > &result) {
    if (i >= nums.size())
        return;
    items.push_back(nums[i]);
    result.push_back(items);
    generate(i + 1, nums, items, result);
    items.pop_back();
    generate(i + 1, nums, items, result);
}

vector<vector<int> > subsets1(vector<int> &nums) {
    vector<int> items;
    vector<vector<int> > result;
    result.push_back(items);
    generate(0, nums, items, result);
    return result;
}

//2.leetcode 78, Subsets,方法2，位运算法
vector<vector<int> > subsets2(vector<int> &nums) {
    int all_set = 1 << nums.size();
    vector<vector<int> > result;
    for (int i = 0; i < all_set; ++i) {
        vector<int> items;
        for (int j = 0; j < nums.size(); ++j) {
            if (i & 1 << j) {
                items.push_back(nums[j]);
            }
        }
        result.push_back(items);
    }
    return result;
}

//3.leetcode 90, SubsetsII
void generate1(int i, vector<int> &nums, vector<int> &items, vector<vector<int> > &result,
               set<vector<int> >&res_set) {
    if (i >= nums.size())
        return;
    items.push_back(nums[i]);
    if(res_set.find(items)==res_set.end())
    {
        result.push_back(items);
        res_set.insert(items);
    }
    generate1(i + 1, nums, items, result,res_set);
    items.pop_back();
    generate1(i + 1, nums, items, result,res_set);
}

vector<vector<int> > subsetsWithDup(vector<int> &nums) {
    vector<vector<int> > result;
    vector<int> item;
    set<vector<int> >res_set;
    sort(nums.begin(), nums.end());
    result.push_back(item);
    generate1(0,nums,item,result,res_set);
    return result;
}

//4.leetcode 40, Combination Sum II
void generate2(int i, vector<int> &nums, vector<int> &items, vector<vector<int> > &result,
               set<vector<int> >&res_set,int sum,int target) {
    if (i >= nums.size() || sum>target)
        return;
    sum += nums[i];
    items.push_back(nums[i]);
    if(res_set.find(items)==res_set.end() && sum==target)
    {
        result.push_back(items);
        res_set.insert(items);
    }
    generate2(i + 1, nums, items, result,res_set,sum,target);
    sum -= nums[i];
    items.pop_back();
    generate2(i + 1, nums, items, result,res_set,sum,target);
}
vector<vector<int> > combinationSum2(vector<int>&candidates,int target)
{
    vector<vector<int> > result;
    vector<int> item;
    set<vector<int> >res_set;
    sort(candidates.begin(),candidates.end());
    generate2(0,candidates,item,result,res_set,0,target);
    return result;
}

//5.leetcode 22, Generate Parentheses
void generate3(string item,int left,int right,vector<string>& result)
{
    if(left==0 && right==0)
    {
        result.push_back(item);
        return;
    }

    if(left>0)
    {
        generate3(item+'(',left-1,right,result);
    }
    if(left<right)
    {
        generate3(item+')',left,right-1,result);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> result;
    generate3("",n,n,result);
    return result;
}

//6.LeetCode 51. N-Queens
void put_down_queue(int x,int y,vector<vector<int> >& mark)
{
    const static int dx[] = {-1,1,0,0,-1,-1,1,1};
    const static int dy[] = {0,0,-1,1,-1,1,-1,1};
    mark[x][y] = 1;
    int new_x;
    int new_y;
    for (int i = 0; i < mark.size(); ++i) {
        for (int j = 0; j < 8; ++j) {
            new_x = x+i*dx[j];
            new_y = y+i*dy[j];
            if(new_x>=0 && new_x<mark.size() &&
               new_y>=0 && new_y<mark.size())
            {
                mark[new_x][new_y] = 1;
            }
        }

    }
}

void generate4(int k,int n,vector<string>& location,
               vector<vector<string> >&result,vector<vector<int> >& mark)
{
    if(k==n)
    {
        result.push_back(location);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if(mark[k][i]==0)
        {
            vector<vector<int> > tmp_mark = mark;
            location[k][i] = 'Q';
            put_down_queue(k,i,mark);
            generate4(k+1,n,location,result,mark);
            mark = tmp_mark;
            location[k][i] = '.';
        }

    }

}

vector<vector<string> > solveNQueens(int n)
{
    vector<string> location;
    vector<vector<string> >result;
    vector<vector<int> > mark;
    for (int i = 0; i < n; ++i) {
        mark.push_back(vector<int>());
        for (int j = 0; j < n; ++j) {
            mark[i].push_back(0);
        }
        location.push_back("");
        location[i].append(n,'.');
    }
    generate4(0,n,location,result,mark);
    return result;
}
