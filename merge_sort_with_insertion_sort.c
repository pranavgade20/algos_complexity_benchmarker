#include <stdlib.h>
#include <stdio.h>

void sort(int* arr, int size);
void insertion_sort(int* arr, int size);
void merge(int* arr1, int size1, int* arr2, int size2, int* arr);
void k_way_merge(int** arrays, int* sizes, int sizes_len, int* result);

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

void merge(int* arr1, int size1, int* arr2, int size2, int* arr) {
    // assuming arr1 and arr2 are sorted, arr3 has enough allocated space
    int k = 0;
    int i = 0;
    int j = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < size2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void k_way_merge(int** arrays, int* sizes, int sizes_len, int* result) {
    // k-way merge arrays and put into result. assuming result has enough space
    while (sizes_len > 1) {
        for (int i = 0; i < sizes_len-1; i+=2) {
            int* arr1 = arrays[i];
            int* arr2 = arrays[i+1];
            int size1 = sizes[i];
            int size2 = sizes[i+1];
            int* res = malloc(sizeof(int) * (size1+size2)); // could optimise to be in-place
            merge(arr1, size1, arr2, size2, res);
            free(arr1);
            free(arr2);
            arrays[i/2] = res;
            sizes[i/2] = size1+size2;
        }

        sizes_len += sizes_len%2;
        sizes_len /= 2;
    }

    for (int i = 0; i < sizes[0]; ++i) {
        result[i] = arrays[0][i];
    }
    free(arrays[0]);
}

void sort(int* arr, int size) {
    int k = 4;
    int* sizes = malloc(sizeof(int) * k); // not free'd
    int** arrays = malloc(sizeof(int*) * k); // not free'd
    int total = 0;
    int ptr = 0;
    for (int i = 0; i < k; ++i) {
        sizes[i] = size/k;
        if (i == k-1) {
            sizes[i] += size%k;
        }
        arrays[i] = malloc(sizeof(int) * sizes[i]);
        for (int j = 0; j < sizes[i]; ++j) {
            arrays[i][j] = arr[ptr++];
        }
        insertion_sort(arrays[i], sizes[i]);
        total += sizes[i];
    }

    int* result = malloc(sizeof(int) * total);

    k_way_merge(arrays, sizes, k, result);
}
