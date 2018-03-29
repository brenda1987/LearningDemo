//
// Created by wyq on 18-3-23.
//

#include "stack.h"


bool IsEmpty(const PSTACK pS)
{
    return  (pS->bottom == pS->top);
}

void init(PSTACK pS)
{
    pS->top = (PNODE)malloc(sizeof(node));
    if (NULL==pS->top)
    {
        printf("malloc failed\n");
        exit(-1);
    }
    else
    {
        pS->bottom = pS->top;
        pS->top->next = NULL;
    }

}

void push(PSTACK pS, int value)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (NULL==pNew)
    {
        printf("malloc failed\n");
        exit(-1);
    }
    pNew->val = value;
    pNew->next = pS->top;
    pS->top = pNew;
    return;


}

void traverse(const PSTACK pS)
{
    PNODE pCur = pS->top;
    while (pCur!=pS->bottom)
    {
        printf("%d ",pCur->val);
        pCur = pCur->next;
    }
    printf("\n");
    return;

}

bool pop(PSTACK pS, int *value)
{
    if (IsEmpty(pS))
        return false;
    else
    {
        PNODE pTemp = pS->top;
        *value = pTemp->val;
        pS->top = pTemp->next;
        free(pTemp);
        pTemp = NULL;
        return true;
    }

}

void clear(PSTACK pS)
{
    if (IsEmpty(pS))
        return;
    else
    {
        PNODE p = pS->top;
        PNODE q = NULL;
        while (p != pS->bottom)
        {
            q = p->next;
            free(p);
            p = q;
        }
        pS->top = pS->bottom;
    }

}

