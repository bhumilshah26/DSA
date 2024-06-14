#include<stdio.h>
#define n 6
#define INF 999
int parent[n];
void initializeparent() {
    int i;
    for(i = 0; i < n; i++)
        parent[i] = i;
}

int find(int i){
    while(parent[i] != i)
        i = parent[i];
    return i;
}

int uni(int i, int j){
    int a = find(i), b = find(j);
    if(a != b){
        parent[b] = a;
        return 1;
    }
    return 0;
}

void kruskals(int cost[][n]){
    int min, ne = 0, i, j, a, b, mincost = 0;
    while(ne < n - 1){
        min = INF;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(find(i) != find(j) && min > cost[i][j]) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
        if(uni(a, b)){
            printf("Edge: %d => (%d, %d) = %d\n", ne + 1, a, b, min);
            ne++;
            mincost += min;
        }
    }
    printf("Mincost: %d ", mincost);
}

int main() {
    return 0;
}