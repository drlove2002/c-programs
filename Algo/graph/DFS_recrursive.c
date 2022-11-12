#include<stdio.h>
#include<stdlib.h>

#define INF 999
int **matrix, v_count, *visited;

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

/*Creating the matrix which is used to store the graph vertices*/
void init_matrix() {
    // Vertex count input
    printf("How many vertices are needed?\n> ");
    scanf("%d", &v_count);

    visited = (int *) calloc(v_count, sizeof(int));
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
    int v1, v2, edge_count;
    printf("How many edges are needed?\n> ");
    scanf("%d", &edge_count);
    printf("\n------------------------------\n");
    printf("> Which two vertexes do you want to connect?\n");
    printf("> Data entry format -> [vertex-1 vertex-2]");
    printf("\n------------------------------\n\n");

    for (int i = 0; i < edge_count; i++) {
        printf("[i]Edge remaining <%d>\n> ", edge_count - i);
        while (1) {
            scanf("%d%d", &v1, &v2);
            matrix[v1 - 1][v2 - 1] = matrix[v2 - 1][v1 - 1] = 1;
            if (v1 <= v_count && v2 <= v_count) {
                printf("\n(%d)--(%d)\n\n", v1, v2);
                break;
            } else
                printf("\nVertex should be less than %d", v_count);
        }
    }
}

void DFS(int i) {
    printf("%d -> ", i + 1);
    visited[i] = 1;
    for (int j = 0; j < v_count; j++) {
        if (!visited[j] && matrix[i][j] == 1) {
            DFS(j);
        }
    }
}

int main() {
    init_matrix();
    crate_graph();

    printf("\nYour created matrix:\n");
    print_2d_array(matrix, v_count, v_count);
    printf("\n");

    int src;
    printf("Enter the source: ");
    scanf("%d", &src);
    src = src > 0 && src <= v_count ? src - 1 : 0;
    DFS(src);
    return 0;
}