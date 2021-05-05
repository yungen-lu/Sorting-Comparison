#include <stdlib.h>

#include "MergeSort-H.h"
void _MergeSort(void *ptrToArray, int start, int end, int (*ptrToFunc)(void *a, void *b), int size) {
    if (start < end) {
        int mid = (start + end) / 2;
        _MergeSort(ptrToArray, start, mid, ptrToFunc, size);
        _MergeSort(ptrToArray, mid + 1, end, ptrToFunc, size);
        _Merge(ptrToArray, start, mid, end, ptrToFunc, size);
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
    }
    free(tmp);
}
