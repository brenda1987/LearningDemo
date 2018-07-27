//
// Created by wyq on 18-7-13.
//

#ifndef PROJECT_LEETCODEBTREE_H
#define PROJECT_LEETCODEBTREE_H

#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;

typedef  struct treeNode
{
    int val;
    struct treeNode* left;
    struct treeNode* right;
    treeNode(int x):val(x),left(NULL),right(NULL) {}
}TreeNode;

//LeetCode 113. Path Sum II
vector<vector<int> > pathSum(TreeNode* root, int sum);

//LeetCode 236. Lowest Common Ancestor of a Binary Tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

//LeetCode 114.Flatten Binary Tree to Linked List
void flatten(TreeNode *root);

//LeetCode 199.Binary Tree Right Side View
vector<int> rightSideView(TreeNode* root);

#endif //PROJECT_LEETCODEBTREE_H
