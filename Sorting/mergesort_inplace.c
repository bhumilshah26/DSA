#include <stdio.h>

void mergeInPlace(int arr[], int l, int m, int r) {
    int i = l;      
    int j = m + 1;   

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            i++;
        } else {
            int temp = arr[j];
            for (int k = j; k > i; k--)
                arr[k] = arr[k - 1];
            arr[i] = temp;
            i++;
            m++;
            j++;
        }
    }
}

void mergeSortInPlace(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        mergeSortInPlace(arr, l, m);
        mergeSortInPlace(arr, m + 1, r);

        mergeInPlace(arr, l, m, r);
    }
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Array is \n");
    printArray(arr, arr_size);

    mergeSortInPlace(arr, 0, arr_size);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);

    return 0;
}
