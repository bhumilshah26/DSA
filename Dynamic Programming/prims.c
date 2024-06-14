#include<stdio.h>
#define n 9
#define INF 999
int g[n][n] = {
    {0, 4, 0, 0, 0, 0, 0, 8, 0},
    {4, 0, 8, 0, 0, 0, 0, 11, 0},
    {0, 8, 0, 7, 0, 4, 0, 0, 2},
    {0, 0, 7, 0, 9, 14, 0, 0, 0},
    {0, 0, 0, 9, 0, 10, 0, 0, 0},
    {0, 0, 4, 14, 10, 0, 2, 0, 0},
    {0, 0, 0, 0, 0, 2, 0, 1, 6},
    {8, 11, 0, 0, 0, 0, 1, 0, 7},
    {0, 0, 2, 0, 0, 0, 6, 7, 0},
};

int key[n], parent[n], visited[n] = {0}, source = 0;


void INITIALIZE_SINGLE_SOURCE() {
    int i;
    for(i = 0; i < n; i++){
        key[i] = INF;
        parent[i] = -1;
    }
    key[source] = 0;
}

void relax(int u, int v) {
    if(key[v] > g[u][v]) {
        key[v] = g[u][v];
        parent[v] = u;
    }
}

int EXTRACT_MIN() {
    int i, min = INF, min_i = -1;
    for(i = 0; i < n; i++)
        if(min > key[i] && !visited[i]) {
            min = key[i];
            min_i = i;
        }
    visited[min_i] = 1;
    return min_i;
}

void PRIM_MST() {
    int i, j;
    INITIALIZE_SINGLE_SOURCE();
    for(i = 0; i < n; i++) {
        int U = EXTRACT_MIN();
        for(j = 0; j < n; j++)
            if(g[U][j] && !visited[j])
                relax(U, j);
    }
}

int main() {
    int i, sum = 0;
    PRIM_MST();
    for(i = 0; i < n; i++)
        sum += key[i];

    printf("Vertex\tKey\tParent\n");
    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\n", i + 1, key[i], parent[i]);

    printf("MST: %d", sum);
    return 0;
}