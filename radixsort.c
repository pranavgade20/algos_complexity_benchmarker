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

void sort_helper(int* arr, int size, int bit) {
    int buckets[16][size];
    int sizes[16] = {0};
    for (int i = 0; i < size; ++i) {
        int pos = (arr[i] & (0xf << bit)) >> bit;
        buckets[pos][sizes[pos]++] = arr[i];
    }
    int pos = 0;
    int ptr = 0;
    for (int i = 0; i < size; ++i) {
        while (ptr >= sizes[pos]) {
            pos++;
            ptr = 0;
        }
        arr[i] = buckets[pos][ptr++];
    }
}

void insertion_sort(int* arr, int size) {
    int max = INT_MIN;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > max) max = arr[i];
    }
    int bit = 0;
    while (max > 0) {
        max /= 2;
        bit++;
    }
    bit -= 4;
    if (bit < 0) bit = 0;

    int ptr = 0;
    sort_helper(arr, size, ptr);
    while (bit >= ptr) {
        ptr += 4;
        sort_helper(arr, size, ptr);
    }
}
