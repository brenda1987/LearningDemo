//
// Created by wyq on 18-6-4.
//


#include "list.h"

int main(void)
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(7);
    ListNode g(8);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &c;

//    bool cycle =  hasCycle(&a);
//    ListNode *node1 =  detectCycle1(&a);
//    printf("%d\n",node1->val);

    ListNode *node2 =  detectCycle2(&a);
    printf("%d\n",node2->val);

    return 0;

}