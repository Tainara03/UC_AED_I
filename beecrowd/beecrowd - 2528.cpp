#include <stdio.h>
#include <stdlib.h>

#define MAXN 1001

struct Node {
    int value;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL)
        return -1;

    struct Node* temp = queue->front;
    int value = temp->value;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    return value;
}

int main() {
    int graph[MAXN][MAXN];
    int n, m, start, end, target;
    int processed[MAXN];
    int dist[MAXN];
    int i, j;

    while (scanf("%d %d", &n, &m) != EOF) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                graph[i][j] = 0;
            }
            processed[i] = 0;
            dist[i] = MAXN;
        }

        while (m--) {
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a][b] = 1;
            graph[b][a] = 1;
        }

        scanf("%d %d %d", &start, &target, &end);

        struct Queue* bfs = createQueue();
        enqueue(bfs, start);
        dist[start] = 0;

        while (bfs->front != NULL) {
            int v = dequeue(bfs);

            if (v == end)
                continue;

            if (v == target) {
                printf("%d\n", dist[v]);
                break;
            }

            for (i = 1; i <= n; i++) {
                if (graph[v][i] && !processed[i]) {
                    processed[i] = 1;
                    dist[i] = dist[v] + 1;
                    enqueue(bfs, i);
                }
            }
        }

        free(bfs);
    }

    return 0;
}
