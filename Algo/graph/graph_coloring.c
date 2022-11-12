#include <stdio.h>
#include <stdlib.h>

int **matrix, *color_arr, v_count, color_count;

/*Print a 2d array*/
void print_2d_array(int **arr, int arr_height, int arr_width) {
    for (int i = 0; i < arr_height; i++) {
        for (int j = 0; j < arr_width; j++)
            printf("%d  ", arr[i][j]);
        printf("\n");
    }
}

/*Print a 1d array*/
void print_vertex_colors(int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("Vertex %d --->  Color %d\n", i + 1, arr[i]);
    printf("\n");
}

/*Creating the matrix which is used to store the graph vertices*/
void init_data() {
    // Vertex count and Color count input
    printf("Vertex count and Color count:\n> ");
    scanf("%d%d", &v_count, &color_count);

    // Allocate location for color array
    color_arr = calloc(v_count, sizeof(int));


    // Allocate location for matrix
    matrix = malloc(v_count * sizeof(int *));
    for (int i = 0; i < v_count; i++)
        matrix[i] = calloc(v_count, sizeof(int));

}

/*Creating the graph based on edge coordinates*/
void crate_graph() {
    int v1, v2, edge_count;
    printf("Edge count:\n> ");
    scanf("%d", &edge_count);
    printf("\n------------------------------\n");
    printf("> Which two vertexes do you want to connect?(It'll create an edge between them)\n> Data entry format -> [vertex-1 vertex-2]");
    printf("\n------------------------------\n\n");

    for (int i = 0; i < edge_count; i++) {
        printf("[i]Edge remaining <%d>\n> ", edge_count - i);
        while (1) {
            scanf("%d%d", &v1, &v2);
            matrix[v1 - 1][v2 - 1] = 1;
            if (v1 <= v_count && v2 <= v_count) {
                printf("\n(%d)---->(%d)\n\n", v1, v2);
                break;
            } else
                printf("\nVertex should be less than %d\n", v_count);
        }
    }
}

int safe_to_color() {
    for (int i = 0; i < v_count; i++)
        for (int j = i + 1; j < v_count; j++)
            if (matrix[i][j] && color_arr[j] == color_arr[i])
                return 0;
    return 1;
}

int coloring(int current_vertex) {
    if (current_vertex == v_count) {
        if (safe_to_color()) {
            printf("Color for each vertex:\n");
            print_vertex_colors(color_arr, v_count);
            return 1;
        }
        return 0;
    }
    for (int color = 1; color <= color_count; ++color) {
        color_arr[current_vertex] = color;
        if (coloring(current_vertex + 1))
            return 1;
        color_arr[current_vertex] = 0;
    }
    return 0;
}

int main() {
    init_data();
    crate_graph();

    printf("Your created matrix:\n");
    print_2d_array(matrix, v_count, v_count);
    printf("\n");

    if (!coloring(0))
        printf("[x] Coloring the graph with %d colors is not possible\n", color_count);
    return 0;
}