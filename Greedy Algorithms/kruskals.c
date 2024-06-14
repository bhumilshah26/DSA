#include <stdio.h>
#include <stdlib.h>
#define mv 6
#define INF 999
int parent[mv];

void initializeParent() {
    for (int i = 0; i < mv; i++)
        parent[i] = i;
}

int find(int i) {
    while (parent[i] != i)
        i = parent[i]; 
    return i;
}

int uni(int i, int j) {
    int a = find(i);
    int b = find(j);
    if (a != b) {
        parent[b] = a;
        return 1;
    }
    return 0;
}

void kruskals(int cost[mv][mv]) {
    int mincost = 0, ne = 0, a, b, min;
    initializeParent();

    printf("The edges of Minimum Cost Spanning Tree are:\n");

    while (ne < mv - 1) {
        min = INF;
        for (int i = 0; i < mv; i++)
            for (int j = 0; j < mv; j++)
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }

        if (uni(a, b)) {
            printf("Edge %d: (%d, %d) = %d\n", ne + 1, a, b, min);
            mincost += min;
            ne++;
        }
    }
    printf("\nMinimum Cost = %d\n", mincost);
}
int main() {
    int cost[mv][mv] = {
        {INF, 2, INF, 8, INF, INF},
        {2, INF, INF, 5, 6, INF},
        {INF, INF, INF, INF, 9, 3},
        {8, 5, INF, INF, 3, 2},
        {INF, 6, 9, 3, INF, 1},
        {INF, INF, 3, 2, 1, INF}};

    kruskals(cost);
    return 0;
}