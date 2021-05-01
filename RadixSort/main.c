#include <stdlib.h>
#include <sys/time.h>

#include "../util/util.h"
#include "RadixSort-H.h"

/* int main() { */
/*     int *ret = scanArrNum("rand.txt", 5); */
/*     myRadixSort(ret, 5); */
/*     printArr(ret, 5); */
/* } */
/* int main(int argc, char *argv[]) { */
/*     int FLAG = getFLAG(argv[1]); */
/*     if (FLAG == 1) { */
/*         int * ret = scanArrNum("rand.txt", 7); */
/*         myRadixSort(ret, 7); */
/*         printArr(ret, 7); */
/*     } else if (FLAG == 2) { */
/*         char **ret = scanArrStr("rand-s.txt", 5); */
/*         _RadixSort(ret, 5); */
/*         printArrStr(ret, 5); */
/*     } else { */
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
        /* printf("err\n"); */
        exit(1);
    }
    arg *arguments = getArg(argv);
    //----------------------------------------------------------------------------------

    int *ret = scanArrNum(arguments->fileName1, arguments->len);
    gettimeofday(&start_tv, NULL);
    myRadixSort(ret, arguments->len);
    gettimeofday(&tv, NULL);
    tmp1 = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    //----------------------------------------------------------------------------------

    gettimeofday(&start_tv, NULL);
    myRadixSort(ret, arguments->len);
    gettimeofday(&tv, NULL);
    tmp2 = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    elapsedNum = (tmp1 + tmp2) / 2;
    //----------------------------------------------------------------------------------

    char **retString = scanArrStr(arguments->fileName2, arguments->len);
    gettimeofday(&start_tv, NULL);
    _RadixSort(retString, arguments->len);
    gettimeofday(&tv, NULL);
    tmp1 = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    //----------------------------------------------------------------------------------

    gettimeofday(&start_tv, NULL);
    _RadixSort(retString, arguments->len);
    gettimeofday(&tv, NULL);
    tmp2 = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    elapsedStr = (tmp1 + tmp2) / 2;
    //----------------------------------------------------------------------------------
    
    writeResault("output/Result.txt", "RadixSort", arguments->len, elapsedStr, elapsedNum);
}
