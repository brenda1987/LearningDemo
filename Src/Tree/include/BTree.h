//
// Created by wyq on 18-4-9.
//

#ifndef PROJECT_BTREE_H
#define PROJECT_BTREE_H

#include <stdio.h>
#include <stdlib.h>


typedef struct btree {
    char data;
    struct btree *lchild;
    struct btree *rchild;
} BTree;

void DCreatTree(BTree *);   //动态创建二叉树
BTree* SCreatTree(void);   //静态创建二叉树
void PreTraverseTree(BTree *);  //递归实现先序遍历
void InTraverseTree(BTree *);   //递归实现中序遍历
void PostTraverseTree(BTree *); //递归实现后序遍历
void PreTraverseTree2(BTree *);//非递归实现先序遍历
void InTraverseTree2(BTree *);//非递归实现中序遍历

#endif //PROJECT_BTREE_H
