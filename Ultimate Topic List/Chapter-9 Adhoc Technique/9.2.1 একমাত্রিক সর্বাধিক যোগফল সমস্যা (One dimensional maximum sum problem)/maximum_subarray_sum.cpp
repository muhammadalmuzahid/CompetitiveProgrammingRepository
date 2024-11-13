#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll maximum_subarray_sum(vector <ll> &v) {
    int n = v.size();
    ll maxSum = v[0], currentSum = v[0];
    for (int i = 1; i < n; i++) {
        currentSum = max(currentSum + v[i], v[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum; // TC: O(N)
}

int main() {
    vector <ll> inputArray = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum: " << maximum_subarray_sum(inputArray) << '\n';
    return 0;
}
