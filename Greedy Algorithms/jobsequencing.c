#include <stdio.h>
#define INF 999

int profit[] = {25, 15, 10, 5, 1};
int deadline[] = {2, 2, 1, 3, 3};
int visited[5] = {0};
int n = 5; // Number of jobs

int findMax() {
    int i, max = -INF, max_i = -1;
    for(i = 0; i < n; i++) 
        if(!visited[i] && max < profit[i]) {
            max = profit[i];
            max_i = i;
        }
    
    if (max_i != -1) 
        visited[max_i] = 1;
    
    return max_i;
}

void jobsequencing() {
    int slot[n], maxprofit = 0;
    int i, j;

    for(i = 0; i < n; i++) 
        slot[i] = -1;

    for(i = 0; i < n; i++) {
        int job = findMax();
        if (job == -1) break; 

        for(j = deadline[job] - 1; j >= 0; j--) 
            if(slot[j] == -1) {
                slot[j] = job;
                maxprofit += profit[job]; 
                break;
            }
    }

    printf("The scheduled jobs are:\n");
    for(i = 0; i < n; i++) 
        if(slot[i] != -1) 
            printf("Job %d (Profit: %d, Deadline: %d) at slot %d\n", slot[i] + 1, profit[slot[i]], deadline[slot[i]], i+1);

    printf("Max Profit: %d\n", maxprofit);       
    
}

int main() {
    jobsequencing();
    return 0;
}
