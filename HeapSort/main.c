#include <stdlib.h>

#include "../util/util.h"
#include "HeapSort-H.h"
#include <sys/time.h>
/* int main() { */
/*     char *string = "rand.txt"; */
/*     int *ret = scanArrNum(string, 5); */
/*     myheapSort(ret, 5); */
/*     printArr(ret, 5); */
/* } */
/* int main(int argc, char *argv[]) { */
/*     int FLAG = getFLAG(argv[1]); */
/*     if (FLAG == 1) { */
/*         char *string = "rand.txt"; */
/*         int *ret = scanArrNum(string, 7); */
/*         _heapSort(ret, 7, cmpnum, sizeof(int)); */
/*         printArr(ret, 7); */
/*     } else if (FLAG == 2) { */
/*         char **ret = scanArrStr("rand-s.txt", 5); */
/*         _heapSort(ret, 5, cmpstr, sizeof(char *)); */
/*         printArrStr(ret, 5); */
/*     } else { */
/*         exit(-1); */
/*     } */
/* } */
int main(int argc, char *argv[]) {
    struct timeval tv;
    struct timeval start_tv;
    double elapsed = 0.0;
    if (checkArg(argv) == 0) {
        /* printf("err\n"); */
        exit(1);
    }
    arg *arguments = getArg(argv);
    /* int FLAG = getFLAG(argv[2]); */
    if (arguments->fileType == 1) {
        int *ret = scanArrNum(arguments->fileName, arguments->len);
        gettimeofday(&start_tv, NULL);
        _heapSort(ret, arguments->len, cmpnum, sizeof(int));
        gettimeofday(&tv, NULL);
        elapsed = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
        writeResault("output/HeapSortResult.txt", "HeapSort", arguments->len, "number", elapsed);
        /* printArr(ret, arguments->len); */
    } else if (arguments->fileType == 2) {
        char **ret = scanArrStr(arguments->fileName, arguments->len);
        gettimeofday(&start_tv, NULL);
        _heapSort(ret, arguments->len, cmpstr, sizeof(char *));
        gettimeofday(&tv, NULL);
        elapsed = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
        writeResault("output/HeapSortResult.txt", "HeapSort", arguments->len, "string", elapsed);
        /* printArrStr(ret, arguments->len); */
    } else {
        exit(1);
    }
}
