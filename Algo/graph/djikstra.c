#include <stdio.h>
#include <stdlib.h>

#define INF 999
int **matrix, v_count;

/*Print a 2d array*/
void print_2d_array(int **arr, int arr_height, int arr_width) {
    for (int i = 0; i < arr_height; i++) {
        for (int j = 0; j < arr_width; j++)
            if (arr[i][j] == INF)
                printf("0,  ");
            else
                printf("%d,  ", arr[i][j]);
        printf("\n");
    }
}

/*Print arr*/
void print_result(int source, int cost[v_count]) {
    printf("\nSource Destination Distance\n");
    for (int i = 1; i <= v_count; i++) {
        printf(" (%d) --> (%d)\t   (%d)\n", source + 1, i, cost[i - 1]);
    }
}

/*Creating the matrix which is used to store the graph vertices*/
void init_matrix() {
    // Vertex count input
    printf("How many vertices are needed?\n> ");
    scanf("%d", &v_count);

    // Allocated location for matrix
    matrix = malloc(v_count * sizeof(int *));
    for (int i = 0; i < v_count; i++)
        matrix[i] = malloc(v_count * sizeof(int));

    // Initialized 0 in all matrix location
    for (int i = 0; i < v_count; i++)
        for (int j = 0; j < v_count; j++)
            matrix[i][j] = (i == j) ? 0 : INF;
}

/*Creating the graph based on edge coordinates*/
void crate_graph() {
    int v1, v2, edge_count, cost;
    printf("How many edges are needed?\n> ");
    scanf("%d", &edge_count);
    printf("\n------------------------------\n");
    printf("> Which two vertexes do you want to connect?(It'll create an edge between them)\n> Data entry format -> [vertex-1 vertex-2 cost]");
    printf("\n------------------------------\n\n");

    for (int i = 0; i < edge_count; i++) {
        printf("[i]Edge remaining <%d>\n> ", edge_count - i);
        while (1) {
            scanf("%d%d%d", &v1, &v2, &cost);
            matrix[v1 - 1][v2 - 1] = matrix[v2 - 1][v1 - 1] = cost;
            if (v1 <= v_count && v2 <= v_count) {
                printf("\n(%d)--[%d]--(%d)\n\n", v1, cost, v2);
                break;
            } else
                printf("\nVertex should be less than %d", v_count);
        }
    }
}

int min_index(int cost[v_count], int visited[v_count]) {
    int min_cost = INF, min_index;
    for (int i = 0; i < v_count; i++)
        if (!visited[i] && cost[i] < min_cost)
            min_cost = cost[i], min_index = i;
    return min_index;
}

/*Main prims algorithm*/
void djikstra() {
    int cost[v_count], *visited, parent[v_count];
    visited = (int *) calloc(v_count, sizeof(int));

    // Initialize arrays
    for (int i = 0; i < v_count; i++)
        cost[i] = matrix[0][i], parent[i] = 0;
    visited[0] = 1, cost[0] = 0;

    // Main algo calculation
    for (int i = 1; i < v_count - 1; i++) {
        int u = min_index(cost, visited);
        visited[u] = 1;
        for (int v = 0; v < v_count; v++) {
            if (!visited[v] && cost[u] + matrix[u][v] < cost[v])
                parent[v] = u, cost[v] = cost[u] + matrix[u][v];
        }
    }
    print_result(0, cost);
}

int main() {
    init_matrix();
    crate_graph();

    printf("\nYour created matrix:\n");
    print_2d_array(matrix, v_count, v_count);
    printf("\n");

    djikstra();
    return 0;
}