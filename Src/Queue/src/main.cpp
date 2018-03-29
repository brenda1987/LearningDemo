//
// Created by wyq on 18-3-26.
//

#include "queue.h"

int main(void)
{
    PQUEUE pQ;
    int value;
    InitQueue(pQ);
    InsertQueue(pQ,5);
    InsertQueue(pQ,50);
    InsertQueue(pQ,500);
    InsertQueue(pQ,5000);
    TraverseQueue(pQ);
    DeleteQueue(pQ,&value);
    TraverseQueue(pQ);
    DestroyQueue(pQ);
    return 0;

}