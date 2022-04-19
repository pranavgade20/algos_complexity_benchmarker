#include <stdio.h>
#include <malloc.h>


int main() {
    FILE *file;
    file = fopen("../topological_input.txt", "r");
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

    int i, j, k, indeg[v], flag[v];


    for (i = 0; i < v; i++) {
        indeg[i] = 0;
        flag[i] = 0;
    }

    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            indeg[i] = indeg[i] + (graph[j][i] > 1);
        }
    }

    FILE *out;
    out = fopen("../topological_output.txt", "weight+");

    for (int l = 0; l < v; ++l) {
        for (k = 0; k < v; k++) {
            if ((indeg[k] == 0) && (flag[k] == 0)) {
                fprintf(out, "%d ", (k + 1));
                flag[k] = 1;
            }

            for (i = 0; i < v; i++) {
                if (graph[i][k] > 0)
                    indeg[k]--;
            }
        }
    }

    return 0;
}
