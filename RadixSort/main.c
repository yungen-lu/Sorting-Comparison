#include <stdlib.h>
#include <sys/time.h>

#include "../util/util.h"
#include "RadixSort-H.h"

int main(int argc, char *argv[]) {
    struct timeval tv;
    struct timeval start_tv;
    double elapsed = 0.0;
    if (checkArg(argv) == 0) {
        exit(1);
    }
    arg *arguments = getArg(argv);
    if (arguments->fileType == 1) {
        int *ret = scanArrNum(arguments->fileName, arguments->len);

        gettimeofday(&start_tv, NULL);
        myRadixSort(ret, arguments->len);
        gettimeofday(&tv, NULL);
        elapsed = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
        writeResault("output/Result.txt", "RadixSort", arguments->len, "number", elapsed);

    } else if (arguments->fileType == 2) {
        char **retString = scanArrStr(arguments->fileName, arguments->len);

        gettimeofday(&start_tv, NULL);
        _RadixSort(retString, arguments->len);
        gettimeofday(&tv, NULL);
        elapsed = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
        writeResault("output/Result.txt", "RadixSort", arguments->len, "string", elapsed);
    }
    return 0;
}
