#include "../util/util.h"
#include "HeapSort-H.h"

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
    }
}
void _heapSort(void *ptrToArray, int length, int (*ptrToFunc)(void *a, void *b), int size) {
    for (int root = length / 2 - 1; root >= 0; root--) {
        _heapify(ptrToArray, length, root, ptrToFunc, size);
    }
    for (int i = length - 1; i > 0; i--) {
        _swap((char *)ptrToArray, (char *)ptrToArray + i * size, size);
        _heapify(ptrToArray, i, 0, ptrToFunc, size);
    }
}

