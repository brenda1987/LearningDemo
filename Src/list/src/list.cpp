//
// Created by wyq on 18-3-20.
//

#include "list.h"

PNODE CreatList(void) {
    int len = 0;
    int i = 0;
    Item val;
    PNODE pHead = (PNODE) malloc(sizeof(NODE));
    if (NULL == pHead) {
        printf("malloc failed\n");
        exit(-1);
    }
    printf("please enter the length of the list:\n");
    scanf("%d", &len);
    PNODE pTail = pHead;
    pTail->next = NULL;
    while (i < len && scanf("%d", &val) == 1) {
        PNODE pCur = (PNODE) malloc(sizeof(NODE));
        if (NULL == pCur) {
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

bool IsEmpty(const PNODE pHead) {
    if (NULL == pHead)
        return true;
    else
        return false;
}

void TranverseList(const PNODE pHead) {

    if (IsEmpty(pHead))
        printf("the list is empty\n");
    else {
        PNODE pCur = pHead->next;
        while (NULL != pCur) {
            printf("%d\t", pCur->value);
            pCur = pCur->next;
        }
    }
    printf("\n");
}

int LengthList(PNODE pHead) {
    if (IsEmpty(pHead)) {
        printf("the list is empty\n");
        return 0;
    } else {
        int len = 0;
        PNODE pCur = pHead->next;
        while (NULL != pCur) {
            ++len;
            pCur = pCur->next;
        }
        return len;
    }

}

bool InsertList(PNODE pHead, int pos, Item value) {
    int i = 0;
    if (pos < 0 || pos > LengthList(pHead) || IsEmpty(pHead))
        return false;
    PNODE pCur = pHead;
    while (i < pos - 1 && pCur != NULL) {
        i++;
        pCur = pCur->next;
    }
    PNODE pNew = (PNODE) malloc(sizeof(NODE));
    if (pNew == NULL) {
        printf("malloc failed\n");
        exit(-1);
    }
    pNew->value = value;
    pNew->next = pCur->next;
    pCur->next = pNew;
    return true;
}

bool DeleteList(PNODE pHead, int pos, Item *pval) {
    int i = 0;
    if (pos < 0 || pos > LengthList(pHead) || IsEmpty(pHead))
        return false;
    PNODE pCur = pHead;
    while (i < pos - 1 && pCur->next != NULL) {
        i++;
        pCur = pCur->next;
    }
    PNODE pTemp = pCur->next;
    *pval = pTemp->value;
    pCur->next = pTemp->next;
    free(pTemp);
    pTemp = NULL;
    return true;
}
