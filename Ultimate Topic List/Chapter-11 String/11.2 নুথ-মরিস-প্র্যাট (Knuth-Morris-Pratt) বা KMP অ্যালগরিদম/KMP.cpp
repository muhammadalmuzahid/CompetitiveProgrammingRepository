#include <bits/stdc++.h>
using namespace std;

vector<int> constructTempArray(string pattern) {
    vector<int> lps(pattern.size());
    int index = 0;
    for (int i = 1; i < (int)pattern.size();) {
        if (pattern[i] == pattern[index]) {
            lps[i] = index + 1;
            ++index;
            ++i;
        } else {
            if (index != 0) {
                index = lps[index - 1];
            } else {
                lps[i] = index;
                ++i;
            }
        }
    }
    return lps;
}
bool KMPMultipleTimes(string text, string pattern) {
    vector<int> lps = constructTempArray(pattern);
    int j = 0, i = 0;
    while (i < (int)text.size()) {
        if (text[i] == pattern[j]) {
            ++i;
            ++j;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                ++i;
            }
        }

        if (j == (int)pattern.size()) {
            return true;
        }
    }
    return false; // O(N + M)
}

int main() {
    string text = "ababcabcabababd";
    string pattern = "ababd";
    if (KMPMultipleTimes(text, pattern)) {
        cout << "Pattern found in the text.\n";
    } else {
        cout << "Pattern not found in the text.\n";
    }
    return 0;
}
