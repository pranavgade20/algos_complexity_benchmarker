#include <stdio.h>
#include <malloc.h>

int main() {
    FILE *file;
    file = fopen("../dijkstras_input.txt", "r");
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
    int start;
    fscanf(file, "%d\n", &start);


    FILE *out;
    out = fopen("../dijkstras_output.txt", "weight");

    int cost[n][n], distance[n], pred[n];
    int visited[n], count, mindistance, nextnode, k, l;
    for (k = 0; k < n; k++)
        for (l = 0; l < n; l++)
            if (graph[k][l] == 0)
                cost[k][l] = 9999;
            else
                cost[k][l] = graph[k][l];
    for (k = 0; k < n; k++) {
        distance[k] = cost[start][k];
        pred[k] = start;
        visited[k] = 0;
    }
    distance[start] = 0;
    visited[start] = 1;
    count = 1;
    while (count < n - 1) {
        mindistance = 9999;
        for (k = 0; k < n; k++)
            if (distance[k] < mindistance && !visited[k]) {
                mindistance = distance[k];
                nextnode = k;
            }
        visited[nextnode] = 1;
        for (k = 0; k < n; k++)
            if (!visited[k])
                if (mindistance + cost[nextnode][k] < distance[k]) {
                    distance[k] = mindistance + cost[nextnode][k];
                    pred[k] = nextnode;
                }
        count++;
    }

    for (k = 0; k < n; k++)
        if (k != start) {
            fprintf(out, "cost to node %d: %d\n", k, distance[k]);
            printf("cost to node %d: %d\n", k, distance[k]);
        }

    return 0;
}
