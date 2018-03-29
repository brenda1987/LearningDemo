//
// Created by wyq on 18-3-23.
//

#ifndef PROJECT_STACK_H
#define PROJECT_STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
}NODE,*PNODE;

typedef struct stack
{
    PNODE top;
    PNODE bottom;
}STACK,*PSTACK;

bool IsEmpty(PSTACK pS);  //栈是否为空

void init(PSTACK pS); //初始化栈

void push(PSTACK pS, int value); //压栈

void traverse(PSTACK pS);

bool pop(PSTACK pS, int *value); //出栈

void clear(PSTACK pS);


#endif //PROJECT_STACK_H
