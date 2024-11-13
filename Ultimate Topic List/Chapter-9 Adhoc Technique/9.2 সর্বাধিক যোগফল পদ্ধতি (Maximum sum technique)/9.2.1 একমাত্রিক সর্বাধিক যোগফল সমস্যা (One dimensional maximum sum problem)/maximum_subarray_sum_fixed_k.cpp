#include <bits/stdc++.h>
using namespace std;

long maximumSumSubarray(int k, vector<int>& a, int n) {
    int l = 0, r = 0;
    long long sum = 0, ans = 0;
    
    while (r < n) {
        sum += a[r];
        
        if ((r - l + 1) == k) {
            ans = max(ans, sum);
            sum -= a[l];
            l++;
        }
        
        r++;
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long result = maximumSumSubarray(k, a, n);
    cout << "Maximum sum of subarray of length " << k << ": " << result << '\n';

    return 0;
}
