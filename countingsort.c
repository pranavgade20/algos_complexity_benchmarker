#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void insertion_sort(int* arr, int size);

int main(int argc, char** argv) {
    int size = argc - 1;
    int* arr = malloc(sizeof(int) * size);
    for (int i = 1; i <= size; ++i) {
        arr[i-1] = atoi(argv[i]);
    }

    insertion_sort(arr, size);

    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

void insertion_sort(int* arr, int size) {
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    int len = max - min + 2;
    int counts[len];
    for (int i = 0; i < len; ++i) counts[i] = 0;
    for (int i = 0; i < size; ++i) counts[arr[i] - min]++;

    int ptr = 0;
    for (int i = 0; i < size; ++i) {
        while (counts[ptr] <= 0) ptr++;
        arr[i] = ptr;
        counts[ptr]--;
    }
}
