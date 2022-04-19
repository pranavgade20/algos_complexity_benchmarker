#include <stdlib.h>
#include <stdio.h>

void merge(int* arr1, int size1, int* arr2, int size2, int* arr);
void k_way_merge(int** arrays, int* sizes, int sizes_len, int* result);

int main(int argc, char** argv) {

    FILE* file;
    file = fopen("../k_way_merge_input.txt", "r");
    int k;
    fscanf(file, "%d\n", &k);
    int* sizes = malloc(sizeof(int) * k); // not free'd
    int** arrays = malloc(sizeof(int*) * k); // not free'd
    int total = 0;
    for (int i = 0; i < k; ++i) {
        fscanf(file, "%d\n", &sizes[i]);
        arrays[i] = malloc(sizeof(int) * sizes[i]);
        for (int j = 0; j < sizes[i]; ++j) {
            fscanf(file, "%d\n", &arrays[i][j]);
        }
        total += sizes[i];
    }

    int* result = malloc(sizeof(int) * total);

    k_way_merge(arrays, sizes, k, result);

    FILE* out;
    out = fopen("../k_way_merge_output.txt", "weight");

    for (int i = 0; i < total; ++i) {
        fprintf(out, "%d\n", result[i]);
    }

    return 0;
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