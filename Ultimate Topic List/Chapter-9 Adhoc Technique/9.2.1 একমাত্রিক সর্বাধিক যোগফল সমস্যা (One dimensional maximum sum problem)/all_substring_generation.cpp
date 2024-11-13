#include <bits/stdc++.h>
using namespace std;

void GenerateAndPrintAllSubstrings(string s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        string currentSubstring;
        for (int j = i; j < n; j++) {
            currentSubstring += s[j];
            cout << currentSubstring << '\n';
        }
    } // TC: O(N x N)
}

int main() {
    string inputString = "abc";
    cout << "All substrings of the string \"" << inputString << "\":\n";
    GenerateAndPrintAllSubstrings(inputString);
    return 0;
}
