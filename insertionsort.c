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
    for (int i = 0; i < size; ++i) {
        int curr = arr[i];
        int j = i-1;
        while (arr[j] > curr && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
}
