//
// Created by wyq on 18-5-30.
//

// leetcode 206,leetcode 92,leetcode 160,leetcode 23

#include <stdio.h>
#include <set>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

//leetcode 206
ListNode* reverseList(ListNode* head)
{
    ListNode* new_head = NULL;
    while (head)
    {
        ListNode* next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
    }
    return new_head;
}

//leetcode 92
ListNode* reverseBetween(ListNode* head, int m, int n)
{
    ListNode* pre_head = NULL;
    ListNode* result = head;
    int change_length = n-m+1;
    while (head && --m)
    {
        pre_head = head;
        head = head->next;
    }
    ListNode* modify_list_tail = head;
    ListNode* new_head = NULL;
    while(head && change_length)
    {
        ListNode* next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
        change_length--;
    }
    modify_list_tail->next = head;
    if (pre_head)
          pre_head->next = new_head;
    else
        result = new_head;
    return  result;
}

//leetcode 160
ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB)
{
    std::set<ListNode*> node_set;
    while (headA)
    {
        node_set.insert(headA);
        headA = headA->next;
    }
    while (headB)
    {
        if(node_set.find(headB) != node_set.end())
            return headB;
        headB = headB->next;
    }
    return NULL;
}

//leetcode 160
int getLength(ListNode* head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return  len;
}

ListNode* forwardLongList(ListNode*head,int length)
{
    while (head && length)
    {
        head = head->next;
        length--;
    }
    return head;
}

ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
{
    int lengthA = getLength(headA);
    int lengthB = getLength(headB);
    if(lengthA > lengthB)
        headA = forwardLongList(headA,lengthA-lengthB);
    else
        headB = forwardLongList(headB,lengthB-lengthA);
    while (headA && headB)
    {
        if(headA==headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

void printList(const ListNode* head)
{
    while (head)
    {
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n ");
}

int main(void)
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode a1(7);
    ListNode b1(8);
    ListNode c1(9);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    a1.next = &b1;
    b1.next = &c1;
    c1.next = &c;
//    ListNode *m = reverseList(&a);
 //   printList(m);
//    ListNode *n = reverseBetween(&a,1,4);
//    printList(n);
    ListNode *k = getIntersectionNode2(&a,&a1);
    printf("%d",k->val);

    return 0;

}