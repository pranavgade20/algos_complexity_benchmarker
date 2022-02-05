#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void sort(int* arr, int size);

int main(int argc, char** argv) {
    int size = atoi(argv[1]);
    int* arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i) {
        arr[i] = rand();
    }

    clock_t start = clock();
    sort(arr, size);
    clock_t diff = clock()-start;

    printf("%ld", diff);

    free(arr);
    return 0;
}

void sort(int* arr, int size) {
    for (int i = 0; i < size-1; ++i) {
        for (int j = 0; j < size-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                int t = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = t;
            }
        }
    }
}
