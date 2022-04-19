#include <stdio.h>
#include <malloc.h>
typedef struct Edge {
    int from;
    int to;
    int weight;
} Edge;

typedef struct Graph {
    int vertices;
    int edges;
    struct Edge *edge;
} Graph;
int main(void) {
    FILE *file;
    file = fopen("../bellman_ford_input.txt", "r");
    FILE *out;
    out = fopen("../bellman_ford_output.txt", "weight");
    Graph *g = malloc(sizeof(Graph));
    fscanf(file, "%d\n", &g->vertices);
    fscanf(file, "%d\n", &g->edges);
    g->edge = (Edge *) malloc(g->edges * sizeof(Edge));
    for (int i = 0; i < g->edges; ++i) {
        fscanf(file, "%d ", &g->edge[i].from);
        fscanf(file, "%d ", &g->edge[i].to);
        fscanf(file, "%d\n", &g->edge[i].weight);
    }

    int j, u, v, w;
    int tV = g->vertices;
    int tE = g->edges;
    int distances[tV];
    int predecessors[tV];

    for (int i = 0; i < tV; i++) {
        distances[i] = 999;
        predecessors[i] = 0;
    }

    distances[0] = 0;

    for (int i = 1; i <= tV - 1; i++) {
        for (j = 0; j < tE; j++) {
            u = g->edge[j].from;
            v = g->edge[j].to;
            w = g->edge[j].weight;
            if (distances[u] != 999 && distances[v] > distances[u] + w) {
                distances[v] = distances[u] + w;
                predecessors[v] = u;
            }
        }
    }

    for (int i = 0; i < tE; i++) {
        u = g->edge[i].from;
        v = g->edge[i].to;
        w = g->edge[i].weight;
        if (distances[u] != 999 && distances[v] > distances[u] + w) {
            fprintf(out, "negative weight cycle\n");
            return 0;
        }
    }

    fprintf(out, "distances: ");
    for (int i = 0; i < tV; i++) {
        fprintf(out, "%d ", distances[i]);
    }
    fprintf(out, "\n");
    fprintf(out, "predecessors: ");

    for (int i = 0; i < tV; i++) {
        fprintf(out, "%d ", predecessors[i]);
    }
    fprintf(out, "\n");
    return 0;
}
