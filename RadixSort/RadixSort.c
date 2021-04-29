#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "RadixSort-H.h"

void myRadixSort(int *ptrToArray, int len) {
    int i = max(ptrToArray, len);
    for (int e = 1; 0 < i / e; e = e * 10) {
        countSort(ptrToArray, len, e);
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
int max(int *ptrToArray, int l) {
    int max = ptrToArray[0];
    for (int i = 1; i < l; i++) {
        if (ptrToArray[i] > max) {
            max = ptrToArray[i];
        }
    }
    return max;
}
void _countSort(char **orginalArr, int len, int e) {
    char *countArr = (char *)malloc(58 * sizeof(char));
    for (int i = 0; i < len; i++) {
        /* printf("%c\n",orginalArr[i][e]); */
        countArr[(orginalArr[i][e] - 'A')]++;
    }
    for (int i = 1; i < 58; i++) {
        countArr[i] += countArr[i - 1];
    }
    char output[len][52];
    for (int x = len - 1; x >= 0; x--) {
        strcpy(output[countArr[(orginalArr[x][e] - 'A')] - 1], orginalArr[x]);
        countArr[(orginalArr[x][e] - 'A')]--;
        /* output[countArr[(orginalArr[x][e] - 'A')] - 1] = orginalArr[x]; */
        /* countArr[(orginalArr[x] / e) % 10]--; */
    }
    for (int i = 0; i < len; i++) {
        /* orginalArr[i] = output[i]; */
        /* printf("|%s|\n",output[i]); */
        strcpy(orginalArr[i], output[i]);
    }
}

void countSort(int *orginalArr, int len, int e) {
    int *countArr = (int *)malloc(len * sizeof(int));
    /* int countArr[len] = {0}; */
    for (int i = 0; i < len; i++) {
        countArr[(orginalArr[i] / e) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        countArr[i] += countArr[i - 1];
    }
    int output[len];
    for (int x = len - 1; x >= 0; x--) {
        output[countArr[(orginalArr[x] / e) % 10] - 1] = orginalArr[x];
        countArr[(orginalArr[x] / e) % 10]--;
    }
    for (int i = 0; i < len; i++) {
        orginalArr[i] = output[i];
    }
}
