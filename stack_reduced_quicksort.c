#include <stdlib.h>
#include <stdio.h>

void insertion_sort(int *arr, int size);

int main(int argc, char **argv) {
    int size = argc - 1;
    int *arr = malloc(sizeof(int) * size);
    for (int i = 1; i <= size; ++i) {
        arr[i - 1] = atoi(argv[i]);
    }

    insertion_sort(arr, size);

    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

void stack_reduced_quick_sort(int *arr, int low, int high) {
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
        i++;
        if (i - low < high - i) {
            stack_reduced_quick_sort(arr, low, i - 1);
            low = i + 1;
        } else {
            stack_reduced_quick_sort(arr, i + 1, high);
            high = i - 1;
        }
    }
}

void insertion_sort(int *arr, int size) {
    stack_reduced_quick_sort(arr, 0, size - 1);
}

