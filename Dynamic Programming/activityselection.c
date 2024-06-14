#include<stdio.h>

#define N 11

int x[N] = {0};

// Start times of the activities
int startTimes[N] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};

// Finish times of the activities
int finishTimes[N] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16}, k = 1;


void activityselection() {
    int i, j, temp, time = finishTimes[0];
    // sort
    for(i = 0; i < N - 1; i++)
        for(j = i + 1; j < N; j++){
            if(finishTimes[i] > finishTimes[j]){
                temp = startTimes[i];
                startTimes[i] = startTimes[j];
                startTimes[j] = temp;
                
                temp = finishTimes[i];
                finishTimes[i] = finishTimes[j];
                finishTimes[j] = temp;
            }
        }
    x[0] = 1;
    for(i = 1; i < N; i++)
        if(time <= startTimes[i]) {
            time = finishTimes[i];
            x[k++] = i + 1;
        }
}

int main(){
    int i;
    activityselection();
    printf("Selected Activities: ");
    for(i = 0 ; i < k; i++)
        printf("%d ", x[i]);
    return 0;
}