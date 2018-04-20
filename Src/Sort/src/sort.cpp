//
// Created by wyq on 18-4-12.
//

#include "sort.h"

void swap(dataType *a, dataType *b) {
    dataType temp = *a;
    *a = *b;
    *b = temp;
}

//冒泡排序
void BubbleSort(dataType A[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1])
                swap(&A[j], &A[j + 1]);
        }
    }
    return;

}

/*选择排序：
 * (1)首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置。
 * (2)然后，再从剩余未排序元素中继续寻找最小（大）元素，放到已排序序列的末尾。
 * (3)以此类推，直到所有元素均排序完毕。
 * */
void SelectSort(dataType A[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (A[i] > A[j])
                swap(&A[i], &A[j]);
        }

    }
    return;

}


//直接插入排序
void InsertSort(dataType A[], int n) {
    int i = 0, j = 0;
    for (i = 1; i < n; i++) {
        int temp = A[i];
        j = i - 1;
        while (j >= 0 && temp < A[j]) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}


//快速排序
void FastSort(dataType A[], int start, int end) {
    if (start >= end)
        return;
    int i = start + 1, j = end;
    int temp = A[start];
    while (i < j) {
        while (i < j && A[j] > temp) {
            j--;
        }
        while (i < j && A[i] < temp) {
            i++;
        }
        swap(&A[i], &A[j]);
    }
    if (A[start] > A[j])
        swap(&A[start], &A[j]);
    FastSort(A, start, j - 1);
    FastSort(A, j + 1, end);
}


//希尔排序
void ShellSort(dataType A[], int n) {
    int i, j;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            for (j = i - gap; j >= 0 && A[j] > A[j + gap]; j -= gap) {
                swap(&A[j], &A[j + gap]);
            }
        }
    }

}


