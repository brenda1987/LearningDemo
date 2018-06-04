//
// Created by wyq on 18-6-4.
//

#ifndef PROJECT_LIST_H
#define PROJECT_LIST_H

#include <stdio.h>

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

#endif //PROJECT_LIST_H
