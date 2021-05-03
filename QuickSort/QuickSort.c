#include "QuickSort-H.h"
#include "util.h"
#include <string.h>
void _quickSort(void *ptrToArray, int start, int end, int (*ptrToFunc)(void *a, void *b), int size) {
    if (start < end) {
        int ret = _partition(ptrToArray, start, end, ptrToFunc, size);
        _quickSort(ptrToArray, start, ret - 1, ptrToFunc, size);
        _quickSort(ptrToArray, ret + 1, end, ptrToFunc, size);
    }
/*     int i,j,pivot, tmp; */
/*     if (start < end) { */
/*         pivot=start; */
/*         i = start; */
/*         j = end; */
/*  */
/*         while (i < j) { */
/*             while ((*ptrToFunc)((char*)ptrToArray + i * size, (char*)ptrToArray + pivot * size) <= 0 && i < end) { */
/*             i++; */
/*             } */
/*             while ((*ptrToFunc)((char *)ptrToArray + j * size,(char*)ptrToArray + pivot * size) > 0) { */
/*             j--; */
/*             } */
/*             if (i < j) { */
/*                 _swap((char*)ptrToArray + i * size, (char*)ptrToArray  + j * size, size); */
/*             } */
/*         } */
/*         _swap((char*)ptrToArray + pivot * size, (char*)ptrToArray + j * size, size); */
/*         _quickSort(ptrToArray, start, j - 1, ptrToFunc, size); */
/*         _quickSort(ptrToArray, j + 1, end, ptrToFunc, size); */
/*     } */
}
int _partition(void *ptrToArray, int start, int end, int (*ptrToFunc)(void *a, void *b), int size) {
    int pivot = start;
    int i = start;
    int j = end;
    while (i < j) {
        while ((*ptrToFunc)((char*)ptrToArray + i * size,  (char*)ptrToArray + pivot * size) <= 0 && i < end) {
            i++;
        }
        while ((*ptrToFunc)( (char*)ptrToArray + j * size,  (char*)ptrToArray + pivot * size) > 0) {
            j--;
        }
        if (i < j) {
            _swap( (char*)ptrToArray + i * size,  (char*)ptrToArray + j * size,size);
        }
    }
    _swap( (char*)ptrToArray + pivot * size,  (char*)ptrToArray + j * size,size);
    return j;
}

