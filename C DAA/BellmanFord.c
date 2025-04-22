#include<stdio.h>
#define n 7
#define INF 999
int d[n] = {0}, parent[n] = {0};
int g[n][n] = {
    {0, 6, 5, 5, 0, 0, 0},
    {0, 0, 0, 0, -1, 0, 0},
    {0, -2, 0, 0, 1, 0, 0},
    {0, 0, -2, 0, 0, -1, 0},
    {0, 0, 0, 0, 0, 0, 3},
    {0, 0, 0, 0, 0, 0, 3},
    {0, 0, 0, 0, 0, 0, 0},
};

void initialize_single_source(){
    int i;
    for(i = 0; i < n; i++)
        d[i] = INF;
    d[0] = 0;
}

void relax(int u, int v) {
    if(d[u] + g[u][v] < d[v]) {
        d[v] = d[u] + g[u][v];
        parent[v] = u;
    }
}

int bellman_ford() {
    int u, v, k;
    initialize_single_source();
    for(k = 0; k < n - 1; k++) 
        for(u = 0; u < n; u++)
            for(v = 0; v < n; v++)
                if(g[u][v])
                    relax(u, v);

    for(u = 0; u < n; u++)
        for(v = 0; v < n; v++)
            if(g[u][v] && d[v] > d[u] + g[u][v])
                return 0;

    return 1;
}



int main() {
    int i, c = bellman_ford();
    if(c) {
        printf("Vertex\tD\tParent\n");
        for(i = 0; i < n; i++)
            printf("%d\t%d\t%d\n", i + 1, d[i], parent[i] + 1);
    }
    else
        printf("No solution");
    return 0;
}