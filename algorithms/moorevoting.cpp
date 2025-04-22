#include<bits/stdc++.h>
using namespace std;

// moorevoting algo: element with frequency > n / 2

int moorevoting(vector<int>& arr) {
    int count = 0;
    int ele;

    for(int a:arr) {
        ele = count ? ele : a;
        count += ele == a ? 1 : -1;
    }
    return ele;
}
int main(){

    vector<int> arr = {3, 3, 4, 5, 6, 2, 3, 3};
    int maxele = moorevoting(arr);

    cout << maxele << " ";

    return 0;
}