#include "../util/util.h"
#include "HeapSort-H.h"

/* void heapify(int *arr, int size, int root) { */
/*     int largest = root; */
/*     int left = root * 2 + 1; */
/*     int right = left + 1; */
/*     if (left < size && arr[left] > arr[largest]) { */
/*         largest = left; */
/*     } */
/*     if (right < size && arr[right] > arr[largest]) { */
/*         largest = right; */
/*     } */
/*     if (largest != root) { */
/*         swap(&arr[root], &arr[largest]); */
/*         heapify(arr, size, largest); */
/*     } */
/* } */

void _heapify(void *ptrToArray, int length, int root, int (*ptrToFunc)(void *a, void *b), int size) {
    int largest = root;
    int left = root * 2 + 1;
    int right = left + 1;
    if (left < length && (*ptrToFunc)((char *)ptrToArray + left * size, (char *)ptrToArray + largest * size) > 0) {
        largest = left;
    }
    if (right < length && (*ptrToFunc)((char *)ptrToArray + right * size, (char *)ptrToArray + largest * size) > 0) {
        largest = right;
    }
    if (largest != root) {
        _swap((char *)ptrToArray + root * size, (char *)ptrToArray + largest * size, size);
        _heapify(ptrToArray, length, largest, ptrToFunc, size);
        /* heapify(arr, length, largest); */
    }
}
void _heapSort(void *ptrToArray, int length, int (*ptrToFunc)(void *a, void *b), int size) {
    for (int root = length / 2 - 1; root >= 0; root--) {
        _heapify(ptrToArray, length, root, ptrToFunc, size);
    }
    for (int i = length - 1; i > 0; i--) {
        /* swap(&arr[0], &arr[i]); */
        /* heapify(arr, i, 0); */
        _swap((char *)ptrToArray, (char *)ptrToArray + i * size, size);
        _heapify(ptrToArray, i, 0, ptrToFunc, size);
    }
}
/* void myheapSort(int *arr, int size) { */
/*     for (int root = size / 2 - 1; root >= 0; root--) { */
/*         heapify(arr, size, root); */
/*     } */
/*     for (int i = size - 1; i > 0; i--) { */
/*         swap(&arr[0], &arr[i]); */
/*         heapify(arr, i, 0); */
/*     } */
/* } */
