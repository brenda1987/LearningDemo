//
// Created by wyq on 18-3-20.
//

#ifndef PROJECT_LIST_H
#define PROJECT_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct node
{
    Item value;
    struct node *next;
}NODE,*PNODE;



PNODE CreatList(void);  //创建列表

bool IsEmpty(const PNODE pHead); //判断列表是否为空

void TranverseList(const PNODE pHead);  //遍历列表

int LengthList(const PNODE pHead);  //求列表长度

bool InsertList(PNODE pHead,int pos,Item value);  //在列表的pos位置插入一个元素value

bool DeleteList(PNODE pHead,int pos,Item *pval);  //删除列表的pos位置的元素

void SortList(PNODE pHead); //对列表进行排序




#endif //PROJECT_LIST_H
