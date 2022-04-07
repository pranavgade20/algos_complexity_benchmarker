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

void insertion_sort(int* arr, int size) {
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
