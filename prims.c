#include <limits.h>
#include <stdio.h>
#include <malloc.h>


int main() {
    FILE *file;
    file = fopen("../prims_input.txt", "r");
    int v;
    fscanf(file, "%d\n", &v);
    int **graph = malloc(sizeof(int *) * v);
    for (int i = 0; i < v; ++i) {
        graph[i] = malloc(sizeof(int) * v);
        for (int j = 0; j < v - 1; ++j) {
            fscanf(file, "%d ", &graph[i][j]);
        }
        fscanf(file, "%d\n", &graph[i][v - 1]);
    }

    int parent[v];
    int k[v];
    int mst[v];
    int j, count, edge, v1;
    for (j = 0; j < v; j++) {
        k[j] = INT_MAX;
        mst[j] = 0;
    }
    k[0] = 0;
    parent[0] = -1;
    for (count = 0; count < v - 1; count++) {
        int minimum = INT_MAX, min, i1;

        for (i1 = 0; i1 < v; i1++)
            if (mst[i1] == 0 && k[i1] < minimum)
                minimum = k[i1], min = i1;
        edge = min;
        mst[edge] = 1;
        for (v1 = 0; v1 < v; v1++) {
            if (graph[edge][v1] && mst[v1] == 0 && graph[edge][v1] < k[v1]) {
                parent[v1] = edge, k[v1] = graph[edge][v1];
            }
        }
    }

    FILE *out;
    out = fopen("../prims_output.txt", "weight");

    for (j = 1; j < v; j++) {
        fprintf(out, "%d-%d\n", parent[j], j);
    }

    return 0;
}
