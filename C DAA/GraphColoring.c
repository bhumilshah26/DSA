#include <stdio.h>
#define n 4

int graph[40][40] = {
    {0, 1, 0, 1},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {1, 0, 1, 0},
};

int m = 2;
int x[n] = {0};

int nextvalue(int k) {
    int i;
    while(1) {
        x[k] = (x[k] + 1) % (m + 1);
        if(x[k] == 0)
            return 0;
        
        for(i = 0; i < n; i++)
            if(graph[k][i] && x[k] == x[i])
                break;

        if(i == n)
            return 1;
    }
}

void mcoloring(int k) {
    int i;
    while(1) {
        if (!nextvalue(k)) 
            return;
        
        
        if(k == n - 1) {

            for(i = 0; i < n; i++)
                printf("%d ", x[i]);

            printf("\n");
        } 
        else 
            mcoloring(k + 1);
        
    }
}

int main() {
    mcoloring(0);
    return 0;
}