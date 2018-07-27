//
// Created by wyq on 18-7-13.
//

#include <queue>
#include "leetCodeBTree.h"

//LeetCode 113. Path Sum II
void preorder(TreeNode *node, int &path_value, int sum, vector<int> &path, vector<vector<int> > &result) {
    if (!node)
        return;
    path_value += node->val;
    path.push_back(node->val);
    if (!node->right && !node->right && path_value == sum)
        result.push_back(path);
    preorder(node->left, path_value, sum, path, result);
    preorder(node->right, path_value, sum, path, result);
    path_value -= node->val;
    path.pop_back();
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > result;
    vector<int> path;
    int path_value = 0;
    preorder(root, path_value, sum, path, result);
    return result;
}


//LeetCode 236. Lowest Common Ancestor of a Binary Tree
void preorder1(TreeNode *node, TreeNode *search, vector<TreeNode *> &path,
               vector<TreeNode *> &result, int &finish) {
    if (!node || finish)
        return;
    path.push_back(node);
    if (node == search) {
        result = path;
        finish = 1;
    }
    preorder1(node->left, search, path, result, finish);
    preorder1(node->right, search, path, result, finish);
    path.pop_back();
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode *> path;
    vector<TreeNode *> node_p_path;
    vector<TreeNode *> node_q_path;
    TreeNode *result = 0;
    int finish = 0;
    preorder1(root, p, path, node_p_path, finish);
    finish = 0;
    path.clear();
    preorder1(root, q, path, node_q_path, finish);
    int path_len = 0;
    if (node_p_path.size() < node_q_path.size())
        path_len = node_p_path.size();
    else
        path_len = node_q_path.size();
    for (int i = 0; i < path_len; ++i) {
        if (node_p_path[i] == node_q_path[i])
            result = node_p_path[i];
    }
    return result;
}

//LeetCode 114.Flatten Binary Tree to Linked List
void preorder2(TreeNode *node, TreeNode *&last) {
    if (!node)
        return;
    if (!node->left && !node->right) {
        last = node;
        return;
    }
    TreeNode *left = node->left;
    TreeNode *right = node->right;
    TreeNode *left_last = NULL;
    TreeNode *right_last = NULL;
    if (left) {
        preorder2(left, left_last);
        node->left = NULL;
        node->right = left;
        last = left_last;
    }
    if (right) {
        preorder2(right, right_last);
        if (left_last)
            left_last->right = right;
        last = right_last;
    }
}

void flatten(TreeNode *root) {
    TreeNode *last = NULL;
    preorder2(root, last);
}

//LeetCode 199.Binary Tree Right Side View
vector<int> rightSideView(TreeNode *root) {
    vector<int> view;
    queue<pair<TreeNode*,int> >Q;
    if (root)
    {
        Q.push(make_pair(root,0));
    }
    while (!Q.empty())
    {
        TreeNode* node = Q.front().first;
        int depth = Q.front().second;
        Q.pop();
        if(view.size()==depth)
            view.push_back(node->val);
        else
            view[depth] = node->val;
        if(node->left)
        {
            Q.push(make_pair(node->left,depth+1));
        }
        if(node->right){
            Q.push(make_pair(node->right,depth+1));
        }
    }
    return view;
}
