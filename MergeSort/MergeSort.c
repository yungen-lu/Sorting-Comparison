#include <stdlib.h>

#include "MergeSort-H.h"
void myMergeSort(int *ptrToArray, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        myMergeSort(ptrToArray, start, mid);
        myMergeSort(ptrToArray, mid + 1, end);
        myMerge(ptrToArray, start, mid, end);
    }
}
void _MergeSort(void *ptrToArray, int start, int end, int (*ptrToFunc)(void *a, void *b), int size) {
    if (start < end) {
        int mid = (start + end) / 2;
        _MergeSort(ptrToArray, start, mid, ptrToFunc, size);
        _MergeSort(ptrToArray, mid + 1, end, ptrToFunc, size);
        _Merge(ptrToArray,start,mid,end,ptrToFunc,size);
    }
}
void _Merge(void *ptrToArray, int start, int mid, int end, int (*ptrToFunc)(void *a, void *b), int size) {
    int arr1Start = start;
    int arr1End = mid;
    int arr2Start = mid + 1;
    int arr2End = end;
    void *tmp = malloc(size * (end - start) + 1);
    int cpyIndex = 0;
    while (arr1Start <= arr1End && arr2Start <= arr2End) {
        if ((*ptrToFunc)(ptrToArray + arr1Start * size, ptrToArray + arr2Start * size) < 0) {
            *((char *)tmp + cpyIndex++ * size) = *((char *)ptrToArray + arr1Start++ * size);
        } else {
            *((char *)tmp + cpyIndex++ * size) = *((char *)ptrToArray + arr2Start++ * size);
        }
    }
    while (arr1Start <= arr1End) {
        *((char *)tmp + cpyIndex++ * size) = *((char *)ptrToArray + arr1Start++ * size);
    }
    while (arr2Start <= arr2End) {
        *((char *)tmp + cpyIndex++ * size) = *((char *)ptrToArray + arr2Start++ * size);
    }
    int j = 0;
    for (int i = start; i <= end; i++) {
        *((char *)ptrToArray + i * size) = *((char *)tmp + j++ * size);
        /* ptrToArray[i] = tmp[j++]; */
    }
}
void myMerge(int *ptrToArray, int start, int mid, int end) {
    int array1start = start;
    int array1end = mid;
    int array2start = mid + 1;
    int array2end = end;
    int *tmp = (int *)malloc(sizeof(int) * (end - start) + 1);
    int cpyPtr = 0;
    while (array1start <= array1end && array2start <= array2end) {
        if (ptrToArray[array1start] < ptrToArray[array2start]) {
            tmp[cpyPtr++] = ptrToArray[array1start++];
        } else {
            tmp[cpyPtr++] = ptrToArray[array2start++];
        }
    }
    while (array1start <= array1end) {
        tmp[cpyPtr++] = ptrToArray[array1start++];
    }
    while (array2start <= array2end) {
        tmp[cpyPtr++] = ptrToArray[array2start++];
    }
    int j = 0;
    for (int i = start; i <= end; i++) {
        ptrToArray[i] = tmp[j++];
    }
}
