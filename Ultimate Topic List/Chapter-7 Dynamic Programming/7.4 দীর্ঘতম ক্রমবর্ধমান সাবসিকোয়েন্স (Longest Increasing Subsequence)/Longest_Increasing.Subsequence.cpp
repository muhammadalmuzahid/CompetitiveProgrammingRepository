#include <bits/stdc++.h>
using namespace std;

vector <long long> LIS_Path(vector <long long>& sequence) {
    long long n = sequence.size();
    vector <long long> sub, subIndex;
    vector <long long> path(n, -1);
    for (long long i = 0; i < n; ++i) {
        if (sub.empty() || sub.back() < sequence[i]) {
            path[i] = sub.empty() ? -1 : subIndex.back();
            sub.push_back(sequence[i]);
            subIndex.push_back(i);
        } 
        else {
            long long idx = lower_bound(sub.begin(), sub.end(), sequence[i]) - sub.begin();
            path[i] = (idx == 0) ? -1 : subIndex[idx - 1];
            sub[idx] = sequence[i];
            subIndex[idx] = i;
        }
    }
    vector <long long> result;
    long long t = subIndex.back();
    while (t != -1) {
        result.push_back(sequence[t]);
        t = path[t];
    }
    reverse(result.begin(), result.end());
    return result; // TC: O(NLogN)
}
int main() {
    vector <long long> v = {1, 3, 5, 4, 6, 2, 8};
    vector <long long> lis = LIS_Path(v);
    for (long long i : lis) { cout << i << ' '; }
}