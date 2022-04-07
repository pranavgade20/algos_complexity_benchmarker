#include <stdlib.h>
#include <stdio.h>

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

void quick_sort(int* arr, int size) {
    if (size < 2) return;

    int pivot = arr[size];
    int i = -1;
    for (int j = 0; j < size; j++) {
        if (arr[j] <= pivot) {
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    i++;
    int t = arr[i];
    arr[i] = arr[size];
    arr[size] = t;

    quick_sort(arr, i - 1);
    quick_sort(&arr[i + 1], size - (i + 1));
}

void insertion_sort(int* arr, int size) {
    quick_sort(arr, size-1);
}

