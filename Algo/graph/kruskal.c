#include <stdio.h>
#include <stdlib.h>

#define INF 999
typedef struct edge {
    int u, v, w;
} edge;
int **matrix, *parent, v_count, edge_count;
edge *edge_list;

/*Print a 2d array*/
void print() {
    printf("\nYour created matrix:\n");
    for (int i = 0; i < v_count; i++) {
        for (int j = 0; j < v_count; j++)
            if (matrix[i][j] == INF)
                printf("*  ");
            else
                printf("%d  ", matrix[i][j]);
        printf("\n");
    }
    printf("\nShorted edge list:\n");
    printf("(u)--[w]--(v)\n");
    for (int i = 0; i < edge_count; ++i) {
        printf("(%d)--[%d]--(%d)\n", edge_list[i].u, edge_list[i].w, edge_list[i].v);
    }
    printf("\n");
}

/*Creating the matrix which is used to store the graph vertices*/
void init_matrix() {
    // Vertex count input
    printf("How many vertices are needed?\n> ");
    scanf("%d", &v_count);
    printf("How many edges are needed?\n> ");
    scanf("%d", &edge_count);
    // Allocated location for data structure
    matrix = malloc(v_count * sizeof(int *));
    for (int i = 0; i < v_count; i++)
        matrix[i] = malloc(v_count * sizeof(int));
    edge_list = (edge *) malloc(edge_count * sizeof(edge));
    parent = (int *) calloc(v_count, sizeof(int));

    // Initialized 0 in all matrix location
    for (int i = 0; i < v_count; i++)
        for (int j = 0; j < v_count; j++)
            matrix[i][j] = (i == j) ? 0 : INF;
}

void sort_edges();

/*Creating the graph based on edge coordinates*/
void crate_graph() {
    edge temp_edge;
    printf("------------------------------\n");
    printf("> Which two vertexes do you want to connect?\n> Data entry format -> [vertex-1 vertex-2 cost]");
    printf("\n------------------------------\n");
    for (int i = 0; i < edge_count; i++) {
        while (1) {
            scanf("%d%d%d", &temp_edge.u, &temp_edge.v, &temp_edge.w);
            matrix[temp_edge.u - 1][temp_edge.v - 1] = matrix[temp_edge.v - 1][temp_edge.u - 1] = temp_edge.w;
            if (temp_edge.u <= v_count && temp_edge.v <= v_count)
                break;
            else
                printf("\nVertex should be less than %d", v_count);
        }
        edge_list[i] = temp_edge;
    }
    sort_edges();
}

/*Helper Functions*/
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

// For sorting the edge_list
void sort_edges() {
    edge temp;
    for (int i = 1; i < edge_count; i++)
        for (int j = 0; j < edge_count - 1; j++)
            if (edge_list[j].w > edge_list[j + 1].w) {
                temp = edge_list[j];
                edge_list[j] = edge_list[j + 1];
                edge_list[j + 1] = temp;
            }
}

/*Main kruskal algorithm*/
void kruskal() {
    int min_cost = 0;
    for (int i = 0; i < edge_count; i++) {
        int x = find(edge_list[i].u);
        int y = find(edge_list[i].v);
        if (uni(x, y)) {
            printf("%d -> %d (%d)\n", edge_list[i].u, edge_list[i].v, edge_list[i].w);
            min_cost = min_cost + edge_list[i].w;
        }
    }
    printf("The cost of minimum spanning tree is : %d\n", min_cost);
}

int main() {
    init_matrix();
    crate_graph();
    print();
    kruskal();
    return 0;
}
