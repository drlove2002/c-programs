// WARSHALL ALGORITHM

#include <stdio.h>
#include <stdlib.h>

int **matrix, v_count;

/*Print a 2d array*/
void print_2d_array(int **arr, int arr_height, int arr_width) {
    for (int i = 0; i < arr_height; i++) {
        for (int j = 0; j < arr_width; j++)
            printf("%d  ", arr[i][j]);
        printf("\n");
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
            matrix[i][j] = 0;
}

/*Creating the graph based on edge coordinates*/
void crate_graph() {
    int v1, v2, edge_count;
    printf("How many edges are needed?\n> ");
    scanf("%d", &edge_count);
    printf("------------------------------\n");
    printf("> Which two vertexes do you want to connect?\n> Data entry format -> [vertex-1 vertex-2]");
    printf("\n------------------------------\n");

    for (int i = 0; i < edge_count; i++) {
        while (1) {
            scanf("%d%d", &v1, &v2);
            if (v1 <= v_count && v2 <= v_count)
                break;
            else
                printf("\nVertex should be less than %d\n", v_count);
        }
        matrix[v1 - 1][v2 - 1] = 1;
    }
}

/*Main WARSHALL algorithm*/
void warshall() {
    // int result_matrix[v_count][v_count];
    for (int i = 0; i < v_count; i++)
        for (int x = 0; x < v_count; x++)
            for (int y = 0; y < v_count; y++)
                matrix[x][y] = (matrix[x][i] && matrix[i][y]) || matrix[x][y];

    printf("Matrix after Warshall algorithm:\n");
    print_2d_array(matrix, v_count, v_count);
}

int main() {
    init_matrix();
    crate_graph();

    printf("Your created matrix:\n");
    print_2d_array(matrix, v_count, v_count);
    printf("\n");
    warshall();

    return 0;
}