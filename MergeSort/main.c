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
    double tmp1 = 0.0;
    double tmp2 = 0.0;
    double elapsedNum = 0.0;
    double elapsedStr = 0.0;

    if (checkArg(argv) == 0) {
        printf("err\n");
        exit(1);
    }
    arg *arguments = getArg(argv);
    //----------------------------------------------------------------------------------

    int *ret = scanArrNum(arguments->fileName1, arguments->len);

    gettimeofday(&start_tv, NULL);
    _MergeSort(ret, 0, arguments->len - 1, cmpnum, sizeof(int));
    gettimeofday(&tv, NULL);
    tmp1 = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    //----------------------------------------------------------------------------------

    gettimeofday(&start_tv, NULL);
    _MergeSort(ret, 0, arguments->len - 1, cmpnum, sizeof(int));
    gettimeofday(&tv, NULL);
    tmp2 = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    elapsedNum = (tmp1 + tmp2) / 2;
    //----------------------------------------------------------------------------------

    char **retString = scanArrStr(arguments->fileName2, arguments->len);
    gettimeofday(&start_tv, NULL);
    _MergeSort(retString, 0, arguments->len - 1, cmpstr, sizeof(char *));
    gettimeofday(&tv, NULL);
    tmp1 = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    //----------------------------------------------------------------------------------

    gettimeofday(&start_tv, NULL);
    _MergeSort(retString, 0, arguments->len - 1, cmpstr, sizeof(char *));
    gettimeofday(&tv, NULL);
    tmp2 = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    elapsedStr = (tmp1 + tmp2) / 2;
    //----------------------------------------------------------------------------------

    writeResault("output/Result.txt", "MergeSort", arguments->len, elapsedStr, elapsedNum);
    return 0;
}
