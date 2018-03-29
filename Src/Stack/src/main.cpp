//
// Created by wyq on 18-3-23.
//

#include "stack.h"

int main(void)
{
    PSTACK pS;
    int value;
    init(pS);
    push(pS,5);
    push(pS,8);
    push(pS,10);
    push(pS,22);
    traverse(pS);

    if (pop(pS,&value))
    {
        printf("value=%d\n",value);
    } else{
        printf("stack is empty\n");
    }

    traverse(pS);
    clear(pS);

    return 0;
}