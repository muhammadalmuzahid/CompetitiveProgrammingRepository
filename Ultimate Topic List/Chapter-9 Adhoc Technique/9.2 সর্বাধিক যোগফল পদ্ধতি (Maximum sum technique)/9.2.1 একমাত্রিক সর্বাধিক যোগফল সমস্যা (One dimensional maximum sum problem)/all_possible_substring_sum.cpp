#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll All_Possible_Substring_Sum(string s) {
    int n = (int)s.size();
    vector<ll> digit_sum(n);
    digit_sum[0] = s[0] - '0';
    ll totalSum = digit_sum[0];
    for (int i = 1; i < n; i++) {
        int cur_val = s[i] - '0';
        digit_sum[i] = (i + 1) * cur_val + 10 * digit_sum[i - 1];
        totalSum += digit_sum[i];
    }
    return totalSum; // TC: O(N)
}

int main() {
    string inputString = "1234";
    cout << "The sum of all possible substrings of \"" << inputString << "\": " << All_Possible_Substring_Sum(inputString) << '\n';
    return 0;
}
