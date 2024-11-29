#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll longestSubstringWithKUniqueChars(string s, ll k) {
    ll start = 0; ll end = 0; ll maxLength = -1; ll uniqueCount = 0;
    vector<ll> charFrequency(26, 0);
    while (end < s.size()) {
        if (charFrequency[s[end] - 'a']++ == 0) { uniqueCount++; }
        while (uniqueCount > k) {
            if (--charFrequency[s[start] - 'a'] == 0) { uniqueCount--; }
            start++;
        }
        if (uniqueCount == k) { maxLength = max(maxLength, end - start + 1); }
        end++;
    }
    return maxLength; // O(N)
}

int main() {
    string s = "aabacbebebe";
    ll k = 3;
    cout << "Input string: " << s << '\n';
    cout << "Number of unique characters (k): " << k << '\n';
    ll result = longestSubstringWithKUniqueChars(s, k);
    if (result != -1) {
        cout << "Length of the longest substring with exactly " << k << " unique characters: " << result << '\n';
    } 
    else {
        cout << "No substring with exactly " << k << " unique characters found.\n";
    }
    return 0;
}
