//
// Created by wyq on 18-4-12.
//

#ifndef PROJECT_SORT_H
#define PROJECT_SORT_H

#include <stdlib.h>

typedef int dataType;

void BubbleSort(dataType A[], int n);  //冒泡排序
void FastSort(dataType A[], int start,int end);    //快速排序
void InsertSort(dataType A[], int n);  //直接插入排序
void SelectSort(dataType A[], int n);  //选择排序
void ShellSort(dataType A[], int n);   //希尔排序
void HeapSort(dataType A[], int n);   //堆排序
void MergeSort(dataType A[], int n);   //归并排序o

#endif //PROJECT_SORT_H
