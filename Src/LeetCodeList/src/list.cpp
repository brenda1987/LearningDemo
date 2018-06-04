//
// Created by wyq on 18-6-4.
//

#include "list.h"
#include <set>


//leetcode 141， 给定一个链表，判断链表中是否有环
bool hasCycle(ListNode *head)
{
    std::set<ListNode *> node_set;
    while (head)
    {
        if(node_set.find(head)!=node_set.end())
            return true;
        node_set.insert(head);
        head = head->next;
    }
    return false;
}

//leetcode 142， 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null
//方法1
ListNode *detectCycle1(ListNode *head)
{
    std::set<ListNode *> node_set;
    while (head)
    {
        if(node_set.find(head)!=node_set.end())
            return head;
        node_set.insert(head);
        head = head->next;
    }
    return NULL;
}

//方法2
ListNode *detectCycle2(ListNode *head)
{
    ListNode* slow = head;
    ListNode* fast = head;
}