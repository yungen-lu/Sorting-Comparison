#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "../util/util.h"
#include "QuickSort-H.h"
/* #include <string.h> */
int main(int argc, char *argv[]) {
    struct timeval tv;
    struct timeval start_tv;
    double elapsed = 0.0;

    if (checkArg(argv) == 0) {
        printf("err\n");
        exit(1);
    }
    arg *arguments = getArg(argv);
    if (arguments->fileType == 1) {
        int *ret = scanArrNum(arguments->fileName, arguments->len);
        gettimeofday(&start_tv, NULL);
        _quickSort(ret, 0, arguments->len - 1, cmpnum, sizeof(int));
        gettimeofday(&tv, NULL);
        elapsed = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
        writeResault("output/QuickSortResult.txt", "QuickSort", arguments->len, "number", elapsed);

    } else if (arguments->fileType == 2) {
        char **retString = scanArrStr(arguments->fileName, arguments->len);
        gettimeofday(&start_tv, NULL);
        _quickSort(retString, 0, arguments->len - 1, cmpstr, sizeof(char *));
        gettimeofday(&tv, NULL);
        elapsed = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);

        writeResault("output/QuickSortResult.txt", "QuickSort", arguments->len, "string", elapsed);
    }
    return 0;
}
