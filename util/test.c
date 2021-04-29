#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

int main() {
    int input;
    int input_read[1000000] = {0};
    struct timeval tv;
    struct timeval start_tv;
    double elapsed = 0.0;
    double elapsed2 = 0.0;
    double elapsed3 = 0.0;
    printf("輸入測資個數：");
    scanf("%d", &input);
    rand_write(input);
    rand_read(input_read);
    //---------------------------------------------------------------------------------------------
    gettimeofday(&start_tv, NULL);
    bub_sort(input_read, input);
    gettimeofday(&tv, NULL);
    sorted_write(input_read, input, 'b');
    elapsed = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    printf("Bubble sort(%d):%f\n", input, elapsed);
    //---------------------------------------------------------------------------------------------
    gettimeofday(&start_tv, NULL);
    ins_sort(input_read, input);
    gettimeofday(&tv, NULL);
    sorted_write(input_read, input, 'i');
    elapsed2 = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    printf("Insertion sort(%d)%f\n", input, elapsed2);
    //---------------------------------------------------------------------------------------------
    gettimeofday(&start_tv, NULL);
    sel_sort(input_read, input);
    gettimeofday(&tv, NULL);
    sorted_write(input_read, input, 's');
    elapsed3 = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    printf("Selection sort(%d)%f\n", input, elapsed3);
}
