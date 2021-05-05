void quickSort(int *ptrToArray, int start, int end);
void _swap(void *a, void *b, int size);
int _partition(void *ptrToArray, int start, int end, int (*ptrToFunc)(void *a, void *b), int size);
void _quickSort(void *ptrToArray, int start, int end, int (*ptrToFunc)(void *a, void *b), int size);
