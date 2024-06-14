#include<stdio.h>
#define n 4
#define INF 999 // asymmetric and left diagonal 0
int A[n][n] = {
    {0, 3, INF, 7},
    {8, 0, 2, INF},
    {5, INF, 0, 1},
    {2, INF, INF, 0},
}, B[n][n];


int min(int x, int y){
    return x > y ? y : x;
}

void floydwarshall(int A[][n]){
    int i, j, k;
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                B[i][j] = min(A[i][j], A[i][k] + A[k][j]);
                
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                A[i][j] = B[i][j];   
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
}

int main(){
    floydwarshall(A);
    return 0;
}