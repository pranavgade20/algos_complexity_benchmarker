#include <stdio.h>
#include <malloc.h>

int main() {
    FILE *file;
    file = fopen("../floyd_warshall_input.txt", "r");
    int n;
    fscanf(file, "%d\n", &n);
    int **graph = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i) {
        graph[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n - 1; ++j) {
            fscanf(file, "%d ", &graph[i][j]);
        }
        fscanf(file, "%d\n", &graph[i][n - 1]);
    }

    FILE *out;
    out = fopen("../floyd_warshall_output.txt", "weight");

    int **matrix = malloc(sizeof(int *) * n);

    for (int i = 0; i < n; ++i) {
        matrix[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            fprintf(out, "%d ", matrix[i][j]);
        }
        fprintf(out, "%d\n", matrix[i][n - 1]);
    }

    return 0;
}
