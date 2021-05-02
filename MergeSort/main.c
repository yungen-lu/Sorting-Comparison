#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "../util/util.h"
#include "MergeSort-H.h"

/* int main(int argc, char *argv[]) { */
/*     int FLAG = getFLAG(argv[1]); */
/*     if (FLAG == 1) { */
/*         char *string = "rand.txt"; */
/*         int *ret = scanArrNum(string, 7); */
/*         int i = 5; */
/*         _MergeSort(ret, 0, 6, cmpnum, sizeof(int)); */
/*         printArr(ret, 7); */
/*     } else if (FLAG == 2) { */
/*         char **ret = scanArrStr("rand-s.txt", 5); */
/*         _MergeSort(ret, 0, 4, cmpstr, sizeof(char *)); */
/*         printArrStr(ret, 5); */
/*     } else { */
/*         exit(-1); */
/*     } */
/* } */
int main(int argc, char *argv[]) {
    struct timeval tv;
    struct timeval start_tv;
    /* double tmp1 = 0.0; */
    /* double tmp2 = 0.0; */
    double elapsed= 0.0;

    if (checkArg(argv) == 0) {
        printf("err\n");
        exit(1);
    }
    arg *arguments = getArg(argv);
    if (arguments->fileType == 1) {
        int *ret = scanArrNum(arguments->fileName, arguments->len);
        gettimeofday(&start_tv, NULL);
        _MergeSort(ret, 0, arguments->len - 1, cmpnum, sizeof(int));
        gettimeofday(&tv, NULL);
        elapsed= ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
        writeResault("output/MergeSortResult.txt", "MergeSort", arguments->len, "number", elapsed);

    } else if (arguments->fileType == 2) {
        char **retString = scanArrStr(arguments->fileName, arguments->len);
        gettimeofday(&start_tv, NULL);
        _MergeSort(retString, 0, arguments->len - 1, cmpstr, sizeof(char *));
        gettimeofday(&tv, NULL);
        elapsed= ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);

        writeResault("output/MergeSortResult.txt", "MergeSort", arguments->len, "string", elapsed);
    }
    return 0;
}
