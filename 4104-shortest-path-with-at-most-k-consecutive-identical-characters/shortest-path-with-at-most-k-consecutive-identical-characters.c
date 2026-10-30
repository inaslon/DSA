#include <stdlib.h>
#include <string.h>

#define INF 1000000000

typedef struct {
    int node;
    int weight;
    int next;
} Edge;

typedef struct {
    int dist;
    int node;
    int consecutive;
} State;

void swap(State* a, State* b) {
    State temp = *a;
    *a = *b;
    *b = temp;
}

void push(State** heap, int* sz, int* capacity, State val) {

    if (*sz + 1 >= *capacity) {
        *capacity *= 2;
        *heap = realloc(*heap, (*capacity) * sizeof(State));
    }

    int x = ++(*sz);
    (*heap)[x] = val;

    while (x > 1 && (*heap)[x].dist < (*heap)[x / 2].dist) {
        swap(&(*heap)[x], &(*heap)[x / 2]);
        x /= 2;
    }
}

State pop(State* heap, int* sz) {

    State ans = heap[1];
    heap[1] = heap[(*sz)--];

    int i = 1;

    while (1) {
        int smallest = i;
        int l = 2 * i;
        int r = 2 * i + 1;

        if (l <= *sz && heap[l].dist < heap[smallest].dist)
            smallest = l;

        if (r <= *sz && heap[r].dist < heap[smallest].dist)
            smallest = r;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return ans;
}

int shortestPath(int n, int** edges, int edgesSize,
                 int* edgesColSize, char* labels, int k) {

    int* head = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        head[i] = -1;

    Edge* adj = malloc(edgesSize * sizeof(Edge));

    int cnt = 0;

    for (int i = 0; i < edgesSize; i++) {

        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[cnt].node = v;
        adj[cnt].weight = w;
        adj[cnt].next = head[u];

        head[u] = cnt++;
    }

    int** dis = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        dis[i] = malloc((k + 1) * sizeof(int));

        for (int j = 0; j <= k; j++)
            dis[i][j] = INF;
    }

    int capacity = 16;
    int sz = 0;

    State* heap = malloc(capacity * sizeof(State));

    dis[0][1] = 0;

    push(&heap, &sz, &capacity, (State){0, 0, 1});

    while (sz > 0) {

        State curr = pop(heap, &sz);

        int d = curr.dist;
        int u = curr.node;
        int consecutive = curr.consecutive;

        if (d > dis[u][consecutive])
            continue;

        if (u == n - 1) {

            for (int i = 0; i < n; i++)
                free(dis[i]);

            free(dis);
            free(head);
            free(adj);
            free(heap);

            return d;
        }

        for (int j = head[u]; j != -1; j = adj[j].next) {

            int v = adj[j].node;
            int w = adj[j].weight;

            int newconsecutive;

            if (labels[u] == labels[v])
                newconsecutive = consecutive + 1;
            else
                newconsecutive = 1;

            if (newconsecutive <= k &&
                dis[v][newconsecutive] > d + w) {

                dis[v][newconsecutive] = d + w;

                push(&heap, &sz, &capacity,
                     (State){d + w, v, newconsecutive});
            }
        }
    }

    for (int i = 0; i < n; i++)
        free(dis[i]);

    free(dis);
    free(head);
    free(adj);
    free(heap);

    return -1;
}