#include "util.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printArr(const int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\n", arr[i]);
    }
}
void printArrStr(const char **arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%s\n", arr[i]);
    }
}
int *scanArrNum(const char *filename, int len) {
    FILE *fptr;
    int *arrOfNum = (int *)calloc(len + 1, sizeof(int));
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        fprintf(stderr, "can not scan file\n");
        return NULL;
    }
    for (int j = 0; j < len; j++) {
        fscanf(fptr, "%d", &arrOfNum[j]);
    }
    fclose(fptr);
    return arrOfNum;
}
char **scanArrStr(const char *filename, int len) {
    FILE *fptr;
    char **arrOfStr = (char **)malloc((len + 1) * sizeof(char *));
    for (int j = 0; j < len; j++) {
        arrOfStr[j] = (char *)malloc(102 * sizeof(char));
    }
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        fprintf(stderr, "can not scan file\n");
        return NULL;
    }
    for (int j = 0; j < len; j++) {
        fscanf(fptr, "%101s", arrOfStr[j]);
    }
    fclose(fptr);
    return arrOfStr;
}
void writeResault(const char *fileName, char *sorttype, int length, char *datatype, double resaultNum) {
    FILE *fptr;
    fptr = fopen(fileName, "a");
    if (fptr == NULL) {
        fprintf(stderr, "can not write to file\n");
    }
    // type | length | time(string) | time(number)
    fprintf(fptr, "%s %d %s %f\n", sorttype, length, datatype, resaultNum);
    fclose(fptr);
}
int getFLAG(const char *string) {
    if (strcmp(string, "-n") == 0)
        return 1;
    else if (strcmp(string, "-s") == 0)
        return 2;
    else
        return 0;
}
// format _filename_ _filetype_ _number_
int checkArg(char *arr[]) {
    if (arr[1] == NULL || !isalpha(arr[1][0])) {
        return 0;
    } else if (arr[2] == NULL || !isalpha(arr[2][1])) {
        return 0;
    } else if (arr[3] == NULL || !isdigit(arr[3][0])) {
        return 0;
    }
    return 1;
}
arg *getArg(char **arr) {
    arg *new = (arg *)malloc(sizeof(arg));
    new->fileName = (char *)malloc(sizeof(char) * 40);
    strcpy(new->fileName, arr[1]);
    new->fileType = getFLAG(arr[2]);
    sscanf(arr[3], "%d", &new->len);
    return new;
}
int cmpStr(void *a, void *b) {
    const char *a1 = *(char **)a;
    const char *b1 = *(char **)b;
    return strcmp(a1, b1);
}
int cmpNum(void *a, void *b) {
    const int *a1 = (int *)a;
    const int *b1 = (int *)b;
    return *a1 - *b1;
}

void _swap(void *a, void *b, int size) {
    char buffer[size];
    memcpy(buffer, a, size);
    memcpy(a, b, size);
    memcpy(b, buffer, size);
}
