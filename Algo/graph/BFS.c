#include<stdio.h>
#include<stdlib.h>

#define INF 999
int **matrix, v_count, *visited, *parent;
int *queue, front = -1, rear = -1;

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

/*Return the distance from source to destination*/
int get_dist(int source, int destination) {
    int total_dist = 0;
    while (1) {
        if (source == destination)
            break;
        total_dist = total_dist + matrix[destination][parent[destination]];
        destination = parent[destination];
    }
    return total_dist;
}

/*Creating the matrix which is used to store the graph vertices*/
void init_matrix() {
    // Vertex count input
    printf("How many vertices are needed?\n> ");
    scanf("%d", &v_count);

    visited = (int *) calloc(v_count, sizeof(int));
    queue = (int *) calloc(v_count, sizeof(int));
    parent = (int *) malloc(v_count * sizeof(int));

    // Allocated location for matrix
    matrix = malloc(v_count * sizeof(int *));
    for (int i = 0; i < v_count; i++) {
        matrix[i] = malloc(v_count * sizeof(int));
        parent[i] = -1;
    }


    // Initialized INF in all matrix location but 0 for diagonal
    for (int i = 0; i < v_count; i++)
        for (int j = 0; j < v_count; j++)
            matrix[i][j] = (i == j) ? 0 : INF;
}

void crate_graph() {
    int v1, v2, cost, edge_count;
    printf("Number of edge:\n> ");
    scanf("%d", &edge_count);
    printf("------------------------------\n");
    printf(" Which two vertexes do you want to connect?\n");
    printf(" Data entry format -> [vertex-1 vertex-2]");
    printf("\n------------------------------\n");

    for (int i = 0; i < edge_count; i++) {
        printf("> ");
        while (1) {
            scanf("%d%d%d", &v1, &v2, &cost);
            if (v1 <= v_count && v2 <= v_count)
                break;
            else
                printf(" [x] Vertex should be less than %d\n> ", v_count);
        }
        matrix[v1 - 1][v2 - 1] = matrix[v2 - 1][v1 - 1] = cost;
    }
}

void insert_queue(int vertex) {
    if (rear == v_count - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = vertex;
    }
}

int isEmpty_queue() {
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

int delete_queue() {
    int delete_item;
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        exit(1);
    }

    delete_item = queue[front];
    front = front + 1;
    return delete_item;
}

void BFS(int v) {
    visited[v] = 1;
    insert_queue(v);
    while (!isEmpty_queue()) {
        v = delete_queue();
        printf("%d -> ", v + 1);
        for (int i = 0; i < v_count; i++) {
            if (matrix[v][i] && matrix[v][i] != INF && visited[i] == 0) {
                insert_queue(i);
                visited[i] = 1;
                parent[i] = v;
            }
        }
    }
}

int main() {
    init_matrix();
    crate_graph();

    printf("\nYour created matrix:\n");
    print_2d_array(matrix, v_count, v_count);
    printf("\n");

    int src, dest;
    printf("Enter the source and specific vertex: ");
    scanf("%d%d", &src, &dest);
    src = src > 0 && src <= v_count ? src - 1 : 0;
    dest = dest > 0 && dest <= v_count ? dest - 1 : 0;
    BFS(src);
    printf("\nDistance from %d to %d is: %d", src + 1, dest + 1, get_dist(src, dest));
    return 0;
}