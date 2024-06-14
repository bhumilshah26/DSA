#include<stdio.h>
int min, max;
void minmax(int arr[], int low, int high){
    int min1, max1, mid;
    if(low == high)
        min = max = arr[low];

    else if(low == high - 1){
        if(arr[low] < arr[high]){
            min = arr[low];
            max = arr[high];
        }
        else {
            min = arr[high];
            max = arr[low];
        }
    }
    else {
        mid = low + (high - low) / 2;
        minmax(arr, low, mid);
        min1 = min;
        max1 = max;
        minmax(arr, mid + 1, high);
        if(min > min1)
            min = min1;
        if(max < max1)
            max = max1;
    }
}

int main(){
    int arr[5] = {21, 34, 22, 56, 76};
    minmax(arr, 0, 4);
    printf("Min: %d\nMax: %d", min, max);

    return 0;
}