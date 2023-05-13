#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct Graph {
    int num_nodes;
    int adj_matrix[MAX_NODES][MAX_NODES];
} Graph;

typedef struct Queue {
    int data[MAX_NODES];
    int front, rear;
} Queue;

void initQueue(Queue *queue) {
    queue->front = queue->rear = -1;
}

int isQueueEmpty(Queue *queue) {
    return (queue->front == -1);
}

void enqueue(Queue *queue, int element) {
    if (queue->rear == MAX_NODES-1) {
        printf("Error: Queue is full\n");
        exit(1);
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->data[queue->rear] = element;
}

int dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Error: Queue is empty\n");
        exit(1);
    }
    int element = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return element;
}

void bfsTraversal(Graph *graph, int start_node) {
    int visited[MAX_NODES] = {0};
    Queue queue;
    initQueue(&queue);

    visited[start_node] = 1;
    printf("%d ", start_node);
    enqueue(&queue, start_node);

    while (!isQueueEmpty(&queue)) {
        int curr_node = dequeue(&queue);
        for (int i = 0; i < graph->num_nodes; i++) {
            if (graph->adj_matrix[curr_node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                printf("%d ", i);
                enqueue(&queue, i);
            }
        }
    }
}
//Best case: O(V + E), Worst case: O(V^2)
//Space Complexity: O(V)
int main() {
    Graph graph;
    graph.num_nodes = 5;

    for (int i = 0; i < graph.num_nodes; i++) {
        for (int j = 0; j < graph.num_nodes; j++) {
            graph.adj_matrix[i][j] = 0;
        }
    }

    graph.adj_matrix[0][1] = 1;
    graph.adj_matrix[0][2] = 1;
    graph.adj_matrix[1][2] = 1;
    graph.adj_matrix[2][0] = 1;
    graph.adj_matrix[2][3] = 1;
    graph.adj_matrix[3][3] = 1;
    graph.adj_matrix[3][4] = 1;

    bfsTraversal(&graph, 2);

    return 0;
}

