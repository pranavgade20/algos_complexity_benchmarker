#include <stdlib.h>
#include <stdio.h>

void sort(int* arr, int size);

int main(int argc, char** argv) {
    int size = argc - 1;
    int* arr = malloc(sizeof(int) * size);
    for (int i = 1; i <= size; ++i) {
        arr[i-1] = atoi(argv[i]);
    }

    sort(arr, size);

    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

void sort(int* arr, int size) {
    for (int i = 0; i < size-1; ++i) {
        int idx = i;
        for (int j = i; j < size; ++j) {
            if (arr[idx] > arr[j]) idx = j;
        }
        int t = arr[idx];
        arr[idx] = arr[i];
        arr[i] = t;
    }
}
