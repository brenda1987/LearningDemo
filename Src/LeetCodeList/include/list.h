//
// Created by wyq on 18-6-4.
//

#ifndef PROJECT_LIST_H
#define PROJECT_LIST_H

#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

//leetcode 141， 给定一个链表，判断链表中是否有环
bool hasCycle(ListNode *head);

//leetcode 142， 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null
ListNode *detectCycle1(ListNode *head);   //方法1
ListNode *detectCycle2(ListNode *head);   //方法2
//leetcode 86,给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前
ListNode* partition(ListNode* head, int x);
//leetcode 23, 合并 k 个排序链表，返回合并后的排序链表
//方法1
ListNode* mergeKLists1(vector<ListNode*>& lists);
//方法2
ListNode* mergeKLists2(vector<ListNode*>& lists);


#endif //PROJECT_LIST_H
