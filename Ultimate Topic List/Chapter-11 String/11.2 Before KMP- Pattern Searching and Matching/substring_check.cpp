#include <bits/stdc++.h>
using namespace std;

bool is_substring(string child, string mother) {
    if (mother.find(child) != string::npos) return true;
    return false; // TC: O(N)
}

int main() {
    string mother = "hello world";
    string child = "world";

    if (is_substring(child, mother)) {
        cout << "\"" << child << "\" is a substring of \"" << mother << "\"\n";
    } else {
        cout << "\"" << child << "\" is not a substring of \"" << mother << "\"\n";
    }
    return 0;
}
