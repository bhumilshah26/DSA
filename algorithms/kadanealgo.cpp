#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// maximum subarray sum
int kadanealgo(vector<int>& arr) {
    int maxsum = 0, sum = 0;

    for(int a:arr) {
        sum += a;

        maxsum = max(maxsum, sum);
        sum = max(sum, 0);
    }
    return maxsum;
}

int main() {

    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int maxsum = kadanealgo(arr);
    cout << maxsum << "\n";

    return 0;
}