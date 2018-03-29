//
// Created by wyq on 18-3-26.
//

#include "queue.h"


void InitQueue(PQUEUE pQ) {
    pQ->front = pQ->rear = (PNODE)malloc(sizeof(NODE));
    if(NULL==pQ->front)
    {
        printf("创建失败，无法分配内存\n");
        exit(-1);
    }
    pQ->front->next = NULL;
    printf("创建成功\n");

}

bool IsEmptyQueue(PQUEUE pQ) {
    return (pQ->front==pQ->rear);
}

void InsertQueue(PQUEUE pQ, int val) {
    PNODE pTemp = (PNODE)malloc(sizeof(NODE));
    if(NULL==pTemp)
    {
        printf("无法分配内存\n");
        exit(-1);
    }
    pTemp->val = val;
    pTemp->next = NULL;
    pQ->rear->next = pTemp;
    pQ->rear = pTemp;
}

void DeleteQueue(PQUEUE pQ, int *val) {
    if (IsEmptyQueue(pQ))
    {
        printf("队列为空,无法出队!\n");
        exit(-1);
    }
    PNODE pN = pQ->front->next;
    *val = pN->val;
    pQ->front->next = pN->next;
    if (pQ->rear==pN)  //防止丢失尾指针
    {
        pQ->rear = pQ->front;
    }
    free(pN);
    pN = NULL;

}


void TraverseQueue(PQUEUE pQ) {
    if (IsEmptyQueue(pQ))
    {
        printf("the queue is empty\n");
        exit(-1);
    }
    PNODE pNew = pQ->front->next;
    while (NULL!=pNew)
    {
        printf("%d\t",pNew->val);
        pNew = pNew->next;
    }
    printf("\n");

}

void ClearQueue(PQUEUE pQ) {
    PNODE pTemp = pQ->front->next;
    pQ->rear = pQ->front;
    pQ->front->next = NULL;
    while (NULL!=pTemp)
    {
        PNODE p = pTemp;
        pTemp = p->next;
        free(p);
        p = NULL;
    }

}

void DestroyQueue(PQUEUE pQ)
{
    while (NULL!=pQ->front) //删除整个队列，包括头节点
    {
        pQ->rear = pQ->front->next;
        free(pQ->front);
        pQ->front = pQ->rear;
    }

}

int LengthQueue(PQUEUE pQ) {
    if (IsEmptyQueue(pQ))
    {
        printf("the queue is empty\n");
        return 0;
    }
    int len = 0;
    PNODE pNew = pQ->front->next;
    while (NULL!=pNew)
    {
        ++len;
        pNew = pNew->next;
    }
    return len;

}