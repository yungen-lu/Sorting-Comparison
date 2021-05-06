void printArr(const int *arr, int len);
int *scanArrNum(const char *string, int len);
char **scanArrStr(const char *filename, int len);
void printArrStr(const char **arr, int len);
int getFLAG(const char *string);
int cmpStr(void *v1, void *v2);
int cmpNum(void *s1, void *s2);
int checkArg(char *arr[]);
void _swap(void *v1, void *v2, int size);
typedef struct {
    char *fileName;
    int fileType;
    int len;
} arg;
arg *getArg(char **arr);
void writeResault(const char *fileName, char *sorttype, int length, char *datatype, double resaultNum);
