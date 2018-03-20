//
// Created by wyq on 18-3-20.
//

#include "list.h"

PNODE CreatList(void)
{
    int len = 0;
    int i=0;
    Item val;
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if(pHead== NULL)
    {
        printf("malloc failed\n");
        exit(-1);
    }
    printf("please enter the length of the list:\n");
    scanf("%d",&len);
    PNODE pTail = pHead;
    pTail->next = NULL;
    while (i<len && scanf("%d",&val)==1)
    {
        PNODE pCur = (PNODE)malloc(sizeof(NODE));
        if(pCur== NULL)
        {
            printf("malloc failed\n");
            exit(-1);
        }
        pCur->value = val;
        pCur->next = NULL;
        pTail->next = pCur;
        i++;
        pTail = pCur;
    }

    return pHead;
}

bool IsEmpty(PNODE pHead)
{
    if (pHead==NULL)
        return true;
    else
        return false;
}

void TranverseList(PNODE pHead)
{

    if (IsEmpty(pHead))
        printf("the list is empty\n");
    else
    {
        PNODE pCur = pHead->next;
        while (pCur != NULL)
        {
            printf("%d\t",pCur->value);
            pCur = pCur->next;
        }
    }
    printf("\n");
}

int LengthList(PNODE pHead)
{
    if (IsEmpty(pHead))
    {
        printf("the list is empty\n");
        return 0;
    }
    else
    {
        int len = 0;
        PNODE pCur = pHead->next;
        while (pCur != NULL)
        {
            len++;
            pCur = pCur->next;
        }
        return len;
    }

}

bool InsertList(PNODE pHead,int pos,Item value)
{
    int i=0;
    PNODE pCur = pHead->next;
    while (i<pos && pCur != NULL)
        i++;
    if(i<pos)
        return false;
    else
    {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
    }


}
