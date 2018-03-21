//
// Created by wyq on 18-3-20.
//

#include "list.h"

int main(void)
{
    Item pval;

    PNODE list = CreatList();

    TranverseList(list);

    LengthList(list);

    InsertList( list,3,5);

    TranverseList(list);

    DeleteList( list,4,&pval);

    TranverseList(list);
}