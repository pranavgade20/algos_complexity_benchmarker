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
        int idx = i;
        for (int j = 0; j < size; ++j) {
            if (arr[idx] > arr[j]) idx = j;
        }
        int t = arr[idx];
        arr[idx] = arr[i];
        arr[i] = t;
    }
}
