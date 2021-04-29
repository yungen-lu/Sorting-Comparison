#include <stdlib.h>

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
    if (checkArg(argv) == 0) {
        /* printf("err\n"); */
        exit(1);
    }
    arg *arguments = getArg(argv);
    /* int FLAG = getFLAG(argv[2]); */
    if (arguments->fileType == 1) {
        int *ret = scanArrNum(arguments->fileName, arguments->len);
        /* _heapSort(ret, arguments->len, cmpnum, sizeof(int)); */
        myRadixSort(ret, arguments->len);
        printArr(ret, arguments->len);
    } else if (arguments->fileType == 2) {
        char **ret = scanArrStr(arguments->fileName, arguments->len);
        /* _heapSort(ret, arguments->len, cmpstr, sizeof(char *)); */
        _RadixSort(ret, arguments->len);
        printArrStr(ret, arguments->len);
    } else {
        exit(1);
    }
}
