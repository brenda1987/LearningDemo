//
// Created by wyq on 18-4-12.
//

#include "sort.h"
#include <stdio.h>

void ArrayPrintf(dataType A[], int len)
{
    int i = 0;
    for (i = 0; i < len; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");


}

int main(void) {
    int a[] = {3, 9, 10, 1, 2, 5, 65, 34, 52};
    int len = sizeof(a) / sizeof(a[0]);
    //   BubbleSort(a,len);
    //   SelectSort(a,len);
    //InsertSort(a, len);
    // FastSort(a, 0,len-1);
     ShellSort(a, len);
    ArrayPrintf(a,len);
}