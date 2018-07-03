//
// Created by wyq on 18-6-4.
//

#include "list.h"





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
    ListNode* meet = NULL;
    while (slow && fast)
    {
        slow = slow->next;
        fast = fast->next;
        if(!fast)
            return NULL;
        fast = fast->next;
        if(slow == fast)
        {
            meet = fast;
            break;
        }
    }
    while (head && meet)
    {
        if(head == meet)
            return head;
        head = head->next;
        meet = meet->next;
    }
    return NULL;
}

//leetcode 86,给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前
ListNode* partition(ListNode* head, int x)
{
    ListNode lesshead(0);
    ListNode morehead(0);
    ListNode* less_ptr = &lesshead;
    ListNode* more_ptr = &morehead;

    while (head)
    {
        if(head->val<x)
        {
            less_ptr->next = head;
            less_ptr = head;
        } else
        {
            more_ptr->next = head;
            more_ptr = head;
        }
        head = head->next;
    }
    less_ptr->next = morehead.next;
    more_ptr->next = NULL;
    return lesshead.next;
}

//leetcode 23, 合并 k 个排序链表，返回合并后的排序链表
//方法1
bool cmp(const ListNode*a, const ListNode* b)
{
    return a->val < b->val;
}

ListNode* mergeKLists1(vector<ListNode*>& lists)
{
    vector<ListNode*> node_vec;
    for(int i=0;i<lists.size();i++)
    {
        ListNode* head = lists[i];
        while (head)
        {
            node_vec.push_back(head);
            head = head->next;
        }
    }
    if(node_vec.size()==0)
    {
        return NULL;
    }
    sort(node_vec.begin(),node_vec.end(),cmp);
    for(int i=1;i<node_vec.size();i++)
    {
        node_vec[i-1]->next = node_vec[i];
    }
    node_vec[node_vec.size()-1]->next = NULL;
    return node_vec[0];
}

//方法2
ListNode* mergeTwoLists(ListNode* l1,ListNode* l2)
{
    ListNode temp_head(0);
    ListNode *pre = &temp_head;
    while (l1 && l2){
        if (l1->val < l2->val){
            pre->next = l1;
            l1 = l1->next;
        }
        else{
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
    }
    if (l1){
        pre->next = l1;
    }
    if (l2){
        pre->next = l2;
    }
    return temp_head.next;

}

ListNode* mergeKLists2(vector<ListNode*>& lists)
{
    if(lists.size()==0)
        return  NULL;
    if(lists.size()==1)
        return lists[0];
    if(lists.size()==2)
        return mergeTwoLists(lists[0],lists[1]);
    int mid = lists.size()/2;
    vector<ListNode*> sub1_lists;
    vector<ListNode*> sub2_lists;
    for(int i=0;i<mid;i++)
        sub1_lists.push_back(lists[i]);
    for(int i=mid;i<lists.size();i++)
        sub2_lists.push_back(lists[i]);
    ListNode* list1 = mergeKLists2(sub1_lists);
    ListNode* list2 = mergeKLists2(sub2_lists);
    return mergeTwoLists(list1,list2);
}