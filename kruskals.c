#include <stdio.h>
#include <malloc.h>

int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];

int find(int);

int uni(int, int);

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    FILE *file;
    file = fopen("../kruskals_input.txt", "r");
    int n;
    fscanf(file, "%d\n", &n);
    int **graph = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i) {
        graph[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n - 1; ++j) {
            fscanf(file, "%d ", &graph[i][j]);
            cost[i][j] = graph[i][j];
        }
        fscanf(file, "%d\n", &graph[i][n - 1]);
        cost[i][n - 1] = graph[i][n - 1];
    }

    FILE *out;
    out = fopen("../kruskals_output.txt", "weight");

    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v)) {
            ne++;
            fprintf(out, "%d-%d\n", a, b);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }



    return 0;
}
