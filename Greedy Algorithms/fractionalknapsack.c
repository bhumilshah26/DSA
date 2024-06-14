#include<stdio.h>
#define n 7
#define INF 999
int weights[n] = {1, 3, 5, 4, 1, 3, 3}, profit[n] = {5, 10, 15, 7, 8, 9, 6}, w = 15, visited[n] = {0};
float maxProfit = 0.0;

int findMax(int r[]) {
    int max = -INF, maxi = 0;
    for (int i = 0; i < n; i++) {
        if(!visited[i] && r[i] > max){
            max = r[i];
            maxi = i;
        }
    }
    visited[maxi] = 1;
    return maxi;
}

void fractionalknapsackratio() {
    float r[n];
    for(int i = 0; i < n; i++)
        r[i] = (float)(profit[i] / weights[i]);
    
    for(int i = 0; i < n; i++) {
        int j = findMax(r); 
        if(w - weights[j] >= 0){
            maxProfit += profit[j];
            w -= weights[j];
        }
        else if(w % weights[j]) {
            maxProfit = maxProfit + (float)w / weights[j] * profit[j];
            w -= w % weights[j];
        }
    }
}

int main(){
    fractionalknapsackratio();
    printf("Max Profit: %f", maxProfit);
    return 0;
}