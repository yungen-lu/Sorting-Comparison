#include "util.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printArr(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\n", arr[i]);
    }
}
void printArrStr(char **arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%s\n", arr[i]);
    }
}
int *scanArrNum(char *filename, int len) {
    FILE *fptr;
    int *arrOfNum = (int *)calloc(len + 1, sizeof(int));
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        fprintf(stderr, "can not scan file\n");
    }
    for (int j = 0; j < len; j++) {
        fscanf(fptr, "%d", &arrOfNum[j]);
    }
    fclose(fptr);
    return arrOfNum;
}
char **scanArrStr(char *filename, int len) {
    FILE *fptr;
    char **arrOfStr = (char **)calloc(len + 1, sizeof(char *));
    for (int j = 0; j < len; j++) {
        arrOfStr[j] = (char *)calloc(20, sizeof(char));
    }
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        fprintf(stderr, "can not scan file\n");
    }
    for (int j = 0; j < len; j++) {
        fscanf(fptr, "%s", arrOfStr[j]);
    }
    fclose(fptr);
    return arrOfStr;
}
void writeResault(char *fileName, char *sorttype, int length, char *test_type, double resault) {
    FILE *fptr;
    fptr = fopen(fileName, "a");
    if (fptr == NULL) {
        fprintf(stderr, "can not write to file\n");
    }
    // type | length | test_type(-s/-n) | time
    fprintf(fptr, "%s %d %s %f\n", sorttype, length, test_type, resault);
    fclose(fptr);
}
int getFLAG(char *string) {
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
int cmpstr(void *v1, void *v2) {
    char *a1 = *(char **)v1;
    char *a2 = *(char **)v2;
    return strcmp(a1, a2);
}
int cmpnum(void *s1, void *s2) {
    int *a = (int *)s1;
    int *b = (int *)s2;
    return *a - *b;
}

void _swap(void *v1, void *v2, int size) {
    // buffer is array of characters which will
    // store element byte by byte
    char buffer[size];

    // memcpy will copy the contents from starting
    // address of v1 to length of size in buffer
    // byte by byte.
    memcpy(buffer, v1, size);
    memcpy(v1, v2, size);
    memcpy(v2, buffer, size);
}
