#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../util/util.h"

void randWriteNum(int count, char *fileName) {
    FILE *fptr;
    fptr = fopen(fileName, "w");
    srand(time(0));
    for (int i = 0; i < count; i++) {
        fprintf(fptr, "%d\n", rand());
    }
    fclose(fptr);
}
void randWriteStr(int len, int count, char *fileName) {
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *randomString;
    FILE *fptr;
    fptr = fopen(fileName, "w");

    srand(time(0));
    for (int i = 0; i < count; i++) {
        randomString = malloc(sizeof(char) * len + 1);

        if (randomString) {
            int l = (int)(sizeof(charset) - 1);
            int key;
            for (int n = 0; n < len; n++) {
                key = rand() % l;
                randomString[n] = charset[key];
            }

            randomString[len] = '\0';
        }
        /* printf("%s\n", randomString); */
        fprintf(fptr, "%s\n", randomString);
        free(randomString);
    }
    fclose(fptr);
}
// output_type | len | fileName
int main(int argc, char *argv[]) {
    int NUM = 0;
    int FLAG = getFLAG(argv[1]);
    char *fileName = argv[3];
    sscanf(argv[2], "%d", &NUM);
    if (FLAG == 1) {
        randWriteNum(NUM, fileName);

    } else if (FLAG == 2) {
        randWriteStr(100, NUM, fileName);
    }
    return 0;
}
