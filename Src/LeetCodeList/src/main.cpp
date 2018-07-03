//
// Created by wyq on 18-6-4.
//


#include "list.h"

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
  /*  ListNode a(1);
    ListNode b(5);
    ListNode c(6);
    ListNode d(4);
    ListNode e(3);
    ListNode f(2);
    ListNode g(8);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;*/

//    bool cycle =  hasCycle(&a);
//    ListNode *node1 =  detectCycle1(&a);
//    printf("%d\n",node1->val);

//    ListNode *node2 =  detectCycle2(&a);
//    printf("%d\n",node2->val);

//    printList(&a);
//    ListNode *head =  partition(&a,4);
//    printList(head);

    ListNode a(1);
    ListNode b(4);
    ListNode c(6);
    ListNode d(0);
    ListNode e(5);
    ListNode f(7);
    ListNode g(2);
    ListNode h(3);
    ListNode k(10);
    a.next = &b;
    b.next = &c;
    d.next = &e;
    e.next = &f;
    g.next = &h;
    h.next = &k;

    vector<ListNode*> lists;
    lists.push_back(&a);
    lists.push_back(&d);
    lists.push_back(&g);

  //  ListNode* new_head1 = mergeKLists1(lists);
    ListNode* new_head2 = mergeKLists2(lists);
    printList(new_head2);

    return 0;

}