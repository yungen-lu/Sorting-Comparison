void quickSort(int *ptrToArray, int start, int end);
void swap(int *a, int *b);
void _swap(void *a,void *b,int size);
int partition(int *ptrToArray, int start, int end);
int _partition(void *ptrToArray, int start, int end, int (*ptrToFunc)(void *a, void *b),int size);
void _quickSort(void *ptrToArray, int start, int end, int (*ptrToFunc)(void *a, void *b),int size);

