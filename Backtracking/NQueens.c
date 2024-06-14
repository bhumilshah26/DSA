#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define n 10

int x[n];


bool place(int k, int i){
    int j;
    for(j = 0; j < k; j++)
        if(x[j] == i || abs(x[j] - i) ==  abs(j - k))
            return false;
    return true;
}

void NQueens(int k, int N){
    int i, j;
    for(i = 0; i < N; i++){
        if(place(k, i)){
            x[k] = i;
            if(k == N - 1){
                for(j = 0; j < N; j++)
                    printf("%d ", x[j] + 1);
                printf("\n");
            }
            else
                NQueens(k + 1, N);
        }
    }
}

int main() {
    NQueens(0, 4);
    return 0;
}