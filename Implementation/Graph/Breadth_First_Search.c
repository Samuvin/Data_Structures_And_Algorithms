#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct _node
{
    int data;
    struct _node *next;
} Node;

Node **Adj_List(int V)
{
    Node **adj = (Node **)malloc(sizeof(Node *) * (V + 1));
    for (int i = 0; i <= V; i++)
    {
        adj[i] = NULL;
    }
    return adj;
}

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void bfs(Node **adj, const int V, const int E, int src)
{
    int q[V], visited[V + 1];
    memset(visited, 0, sizeof(visited));
    int front = 0;
    int rear = 0;
    q[rear++] = src;
    visited[src] = 1;
    while (front != rear)
    {
        int node = q[front++];
        printf("%d ", node);
        for (Node *nbr = adj[node]; nbr; nbr = nbr->next)
        {
            if (!visited[nbr->data])
            {
                q[rear++] = nbr->data;
                visited[nbr->data] = 1;
            }
        }
    }
}

void add_Edge(Node **adj, int u, int v)
{
    Node *node = createNode(v);
    node->next = adj[u];
    adj[u] = node;

    node = createNode(u);
    node->next = adj[v];
    adj[v] = node;
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);
    Node **adj = Adj_List(V);
    int u, v;
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d", &u, &v);
        add_Edge(adj, u, v);
    }
    bfs(adj, V, E, 1);
}