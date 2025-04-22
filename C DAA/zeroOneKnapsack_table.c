#include<stdio.h>
#define n 4
#define m 8
int c = 1;

int max(int x, int y){
    return x > y ? x : y;
}

void sort(int w[], int p[]) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(w[i] > w[j]) {
                int temp = w[i];
                w[i] = w[j];
                w[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int knapsack(int w[], int p[]){
    int dp[n + 1][m + 1];
    // sort(w, p);

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(w[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + p[i - 1]);
            else    
                dp[i][j] = dp[i - 1][j];
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++)
            printf("%d ", dp[i][j]);
        printf("\n");
    }
    printf("\n\n");
    return dp[n][m];
}



int main(){
    int w[n] = {3, 4, 6, 5};
    int p[n] = {2, 3, 1, 4};

    int maxprofit = knapsack(w, p);
    printf("Maxprofit: %d\n", maxprofit);
    return 0;
}