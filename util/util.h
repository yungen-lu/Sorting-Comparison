void printArr(int *arr, int len);
int *scanArrNum(char *string, int len);
char **scanArrStr(char *filename, int len);
void printArrStr(char **arr, int len);
int getFLAG(char *string);
int cmpstr(void *v1, void *v2);
int cmpnum(void *s1, void *s2);
int checkArg(char *arr[]);
void _swap(void *v1, void *v2, int size);
typedef struct {
    char *fileName1;
    char *fileName2;
    /* int fileType; */
    int len;
} arg;
arg *getArg(char **arr);
void writeResault(char *fileName, char *sorttype, int length, double resaultStr, double resaultNum);
