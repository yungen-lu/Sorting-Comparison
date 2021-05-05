void printArr(int *arr, int len);
int *scanArrNum(char *string, int len);
char **scanArrStr(char *filename, int len);
void printArrStr(char **arr, int len);
int getFLAG(char *string);
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
void writeResault(char *fileName, char *sorttype, int length, char *datatype, double resaultNum);
