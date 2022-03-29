#include <stdlib.h>
#include <stdio.h>

void sort(int *arr, int size);

int main(int argc, char **argv) {
    int size = argc - 1;
    int *arr = malloc(sizeof(int) * size);
    for (int i = 1; i <= size; ++i) {
        arr[i - 1] = atoi(argv[i]);
    }

    sort(arr, size);

    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

void stack_reduced_quick_sort(int* arr, int low, int high) {
    int q;
    while (low < high) {
        int pivot = high;
        int i = low - 1, j;
        for (j = low; j < high; j++) {
            if (arr[j] <= arr[pivot]) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[pivot];
        arr[pivot] = temp;
        q = i + 1;
        if (q - low < high - q) {
            stack_reduced_quick_sort(arr, low, q - 1);
            low = q + 1;
        } else {
            stack_reduced_quick_sort(arr, q + 1, high);
            high = q - 1;
        }
    }
}

void sort(int *arr, int size) {
    stack_reduced_quick_sort(arr, 0, size - 1);
}

