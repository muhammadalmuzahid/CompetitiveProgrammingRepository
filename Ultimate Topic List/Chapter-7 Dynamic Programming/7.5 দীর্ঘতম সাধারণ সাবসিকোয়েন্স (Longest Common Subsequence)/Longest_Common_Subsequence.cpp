#include <bits/stdc++.h>
using namespace std;

int LCS(string& s1, string& s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    vector<int> dp(len2 + 1, 0);
    for (int i = 1; i <= len1; i++) {
        int prevDiagonal = 0;
        for (int j = 1; j <= len2; j++) {
            int temp = dp[j];
            if (s1[i - 1] == s2[j - 1]) { dp[j] = prevDiagonal + 1; } 
            else { dp[j] = max(dp[j], dp[j - 1]); }
            prevDiagonal = temp;
        }
    }
    return dp[len2]; // TC: O(N x M) | SC: O(N)
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << "String 1: " << s1 << '\n';
    cout << "String 2: " << s2 << '\n';
    int lcsLength = LCS(s1, s2);
    cout << "Length of Longest Common Subsequence: " << lcsLength << '\n';
    return 0;
}
