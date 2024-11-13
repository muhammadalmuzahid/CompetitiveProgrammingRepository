#include <bits/stdc++.h>
using namespace std;

bool is_subsequence(string& s1, string& s2) {
    int n = s1.length(), m = s2.length();
    int i = 0, j = 0;
    
    while (i < n && j < m) {
        if (s1[i] == s2[j]) i++;
        j++;
    }
    return i == n; // TC: O(len(s2))
}

int main() {
    string s1 = "abc"; // Subsequence to check
    string s2 = "ahbgdc"; // Main string

    if (is_subsequence(s1, s2)) {
        cout << "\"" << s1 << "\" is a subsequence of \"" << s2 << "\"\n";
    } else {
        cout << "\"" << s1 << "\" is not a subsequence of \"" << s2 << "\"\n";
    }

    return 0;
}
