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


void merge_sort(int* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        int n1 = m - l + 1;
        int n2 = r - m;
        int l1[n1], m1[n2];

        for (int i = 0; i < n1; i++) l1[i] = arr[l + i];
        for (int j = 0; j < n2; j++) m1[j] = arr[m + 1 + j];

        int i, j, k;
        i = 0;
        j = 0;
        k = l;

        while (i < n1 && j < n2) {
            if (l1[i] <= m1[j]) {
                arr[k] = l1[i];
                i++;
            } else {
                arr[k] = m1[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = l1[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = m1[j];
            j++;
            k++;
        }
    }
}
void insertion_sort(int* arr, int size) {
    merge_sort(arr, 0, size-1);
}

