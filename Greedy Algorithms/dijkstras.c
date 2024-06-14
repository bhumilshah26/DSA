#include<stdio.h>
#define n 9
#define INF 999
#define NIL -1
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

int key[n] = {0}, parent[n] = {0}, visited[n] = {0};

void INITIALIZA_SINGLE_SOURCE(){
    int i;
    for(i = 0; i < n; i++){
        key[i] = INF;
        parent[i] = NIL;
    }
    key[0] = 0;
}

int EXTRACT_MIN(){
    int i, min = INF, min_i = -1;
    for(i = 0; i < n; i++)
        if(min > key[i] && !visited[i]){
            min = key[i];
            min_i = i;
        }
    
    visited[min_i] = 1;
    return min_i;
}

void relax(int u, int v) {
    if(key[u] + g[u][v] < key[v]){
        key[v] = g[u][v] + key[u];
        parent[v] = u;
    }
}

void dijsktra(){
    int i, j;
    INITIALIZA_SINGLE_SOURCE();
    for(i = 0; i < n; i++){
        int U = EXTRACT_MIN();
        for(j = 0; j < n; j++)
            if(g[U][j] && !visited[j])
                relax(U, j);
    }
}


int main() {
    int i;
    dijsktra();
    printf("Vertex\tDistance\tParent\n");

    for (int i = 0; i < n; i++)
        printf("%c\t%d\t\t%c\n", i + 65, key[i], parent[i] + 65 != '@' ? parent[i] + 65 : '-');
        
    return 0;
}