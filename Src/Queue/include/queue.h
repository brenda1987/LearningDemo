//
// Created by wyq on 18-3-26.
//

#ifndef PROJECT_QUEUE_H
#define PROJECT_QUEUE_H

#include <stdlib.h>
#include <stdio.h>

#define MAX_QUEUE_SIZE 10

typedef struct node {
    int val;
    struct node *next;
} NODE, *PNODE;

typedef struct queue {
    PNODE front;
    PNODE rear;
} QUEUE, *PQUEUE;


void InitQueue(PQUEUE);    //    创建队列函数
bool IsEmptyQueue(PQUEUE pQ);    //    判断队列是否为空函数
void InsertQueue(PQUEUE, int val);    //    入队函数
void DeleteQueue(PQUEUE, int *val);    //    出队函数
void DestroyQueue(PQUEUE);    //    摧毁队列函数
void TraverseQueue(PQUEUE);    //    遍历队列函数
void ClearQueue(PQUEUE);    //    清空队列函数
int LengthQueue(PQUEUE);    //    求队列长度函数


#endif //PROJECT_QUEUE_H
