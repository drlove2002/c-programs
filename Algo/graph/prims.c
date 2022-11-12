#include <stdio.h>
#include <stdlib.h>

#define INF 999
int **matrix, v_count;

/*Print a 2d array*/
void print_2d_array(int **arr, int arr_height, int arr_width) {
    for (int i = 0; i < arr_height; i++) {
        for (int j = 0; j < arr_width; j++)
            if (arr[i][j] == INF)
                printf("*  ");
            else
                printf("%d  ", arr[i][j]);
        printf("\n");
    }
}

/*Print a minimum spanning tree*/
void print_mst(int *parent) {
    printf("\nEdge \tCost\n");
    for (int i = 1; i < v_count; i++)
        printf("%d - %d \t%d \n", parent[i] + 1, i + 1, matrix[i][parent[i]]);
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
    printf("------------------------------\n");
    printf("> Which two vertexes do you want to connect?\n> Data entry format -> [vertex-1 vertex-2 cost]");
    printf("\n------------------------------\n");

    for (int i = 0; i < edge_count; i++) {
        while (1) {
            scanf("%d%d%d", &v1, &v2, &cost);
            if (v1 <= v_count && v2 <= v_count) {
                break;
            } else
                printf("\nVertex should be less than %d", v_count);
        }
        matrix[v1 - 1][v2 - 1] = matrix[v2 - 1][v1 - 1] = cost;
    }
}

int min_index(int cost[v_count], int visited[v_count]) {
    int min_cost = INF, min_index = -1;
    for (int i = 0; i < v_count; ++i)
        if (!visited[i] && cost[i] < min_cost)
            min_cost = cost[i], min_index = i;
    return min_index;
}

/*Main prims algorithm*/
int prims() {
    int cost[v_count], *visited, *parent, total_cost = 0;
    parent = (int *) calloc(v_count, sizeof(int));
    visited = (int *) calloc(v_count, sizeof(int));
    // Initialize cost arr
    for (int i = 0; i < v_count; ++i)
        cost[i] = INF;
    parent[0] = -1, cost[0] = 0;

    // Main algo calculation
    for (int i = 0; i < v_count; ++i) {
        int u = min_index(cost, visited);
        visited[u] = 1;
        if (parent[u] != -1)
            total_cost = total_cost + matrix[u][parent[u]];
        for (int v = 0; v < v_count; ++v) {
            if (matrix[u][v] && !visited[v] && matrix[u][v] < cost[v])
                parent[v] = u, cost[v] = matrix[u][v];
        }
    }
    print_mst(parent);
    return total_cost;
}

int main() {
    init_matrix();
    crate_graph();

    printf("\nYour created matrix:\n");
    print_2d_array(matrix, v_count, v_count);
    printf("\n");

    printf("Weight of minimum spanning tree is %d.", prims());
    return 0;
}