#include <bits/stdc++.h>
using namespace std;

void String_Permutations(string s) { // TC: O(n x n!)
    sort(s.begin(), s.end());
    do {
        cout << s << '\n';
    } while (next_permutation(s.begin(), s.end()));
}

int main() {
    string inputString = "abc";
    cout << "All permutations of the string \"" << inputString << "\":\n";
    String_Permutations(inputString);
    return 0;
}
