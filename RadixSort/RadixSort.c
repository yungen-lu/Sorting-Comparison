#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "RadixSort-H.h"

int max(int *ptrToArray, int l) {
    int max = ptrToArray[0];
    for (int i = 1; i < l; i++) {
        if (ptrToArray[i] > max) {
            max = ptrToArray[i];
        }
    }
    return max;
}
void myRadixSort(int *ptrToArray, int len) {
    int i = max(ptrToArray, len);
    int e;
    for (e = 1; 0 < i / e; e = e * 10) {
        countSort(ptrToArray, len, e);
    }
}
void countSort(int *orginalArr, int len, int e) {
    long int i;
    long int countArr[10] = {0};
    for (i = 0; i < len; i++) {
        countArr[(orginalArr[i] / e) % 10]++;
    }
    for (i = 1; i < 10; i++) {
        countArr[i] += countArr[i - 1];
    }
    int *output = (int *)malloc(sizeof(int) * len);
    for (i = len - 1; i >= 0; i--) {
        output[countArr[(orginalArr[i] / e) % 10] - 1] = orginalArr[i];
        countArr[(orginalArr[i] / e) % 10]--;
    }
    for (i = 0; i < len; i++) {
        orginalArr[i] = output[i];
    }
}
void _RadixSort(char **ptrToArray, int len) {
    int i = _max(ptrToArray, len);
    for (i -= 1; i >= 0; i--) {
        _countSort(ptrToArray, len, i);
    }
}
int _max(char **ptrToArray, int len) {
    int max = strlen(ptrToArray[0]);
    for (int i = 1; i < len; i++) {
        int tmp = strlen(ptrToArray[i]);
        if (tmp > max) {
            max = tmp;
        }
    }
    return max;
}
void _countSort(char **orginalArr, int len, int e) {
    int countArr[60] = {0};
    for (int i = 0; i < len; i++) {
        countArr[(orginalArr[i][e] - 'A')]++;
    }
    for (int i = 1; i < 58; i++) {
        countArr[i] += countArr[i - 1];
    }
    char **output = (char **)malloc(sizeof(char *) * len);
    for (long j = 0; j < len; j++) {
        output[j] = (char *)malloc(sizeof(char) * 10);
    }
    for (long x = len - 1; x >= 0; x--) {
        output[countArr[(orginalArr[x][e] - 'A')] - 1] = orginalArr[x];
        countArr[(orginalArr[x][e] - 'A')]--;
    }
    for (int i = 0; i < len; i++) {
        orginalArr[i] = output[i];
    }
}

