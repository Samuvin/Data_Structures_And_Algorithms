#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int **Adj_Mat(int V)
{
    int **adj = (int **)malloc(sizeof(int *) * (V + 1));
    for (int i = 0; i <= V; i++)
        adj[i] = (int *)calloc(V + 1, sizeof(int));
    return adj;
}

void addEdge(int **adj_mat, int u, int v)
{
    adj_mat[u][v] = 1;
    adj_mat[v][u] = 1;
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);
    int **adj = Adj_Mat(V);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}
