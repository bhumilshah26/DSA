#include<stdio.h>
#define n 4
#define INF 999
int d[]= {5, 4, 6, 2, 7};
int M[n][n], S[n][n];

void initialze() {
    int i, j;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++) 
            M[i][j] = S[i][j] = 0;
        
}

void solution(int i, int j){
    if (i == j)
        printf(" A%d ", i);
    else {
        printf(" ( ");
        solution(i, S[i][j]);
        solution(S[i][j] + 1, j);
        printf(" ) ");
    }
}

void mcm() {
    int i, j, k, min = INF, min_i = -1, len = 1;
    initialze();
    for(len = 1; len <= n; len++)
        for(i = 1; i <= n - len; i++){
            j = i + len;
            for(k = i; k < j; k++) {
                if(min > M[i][k] + M[k + 1][j] + d[i - 1] * d[j] * d[k]){
                    min = M[i][k] + M[k + 1][j] + d[i - 1] * d[j] * d[k];
                    min_i = k;
                }
            }
            M[i][j] = min;
            S[i][j] = min_i;
            min = INF;
            min_i = -1;
        }

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }
        printf("\n");
        printf("\n");
        printf("\n");

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++)
            printf("%d ", S[i][j]);
        printf("\n");
    }

    solution(1, 4);
}



int main(){
    mcm();
    return 0;
}