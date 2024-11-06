#include "bits/stdc++.h"
using namespace std;

// Function to read __int128 from standard input
istream &operator>>(istream &in, __int128 &num) {
    string s;
    in >> s;
    num = 0;
    bool negative = (s[0] == '-');
    for (int i = negative ? 1 : 0; i < s.size(); i++) {
        num = num * 10 + (s[i] - '0');
    }
    if (negative) num = -num;
    return in;
}

// Function to print __int128 to standard output
ostream &operator<<(ostream &out, __int128 num) {
    if (num == 0) return out << "0";
    if (num < 0) {
        out << '-';
        num = -num;
    }
    string s;
    while (num > 0) {
        s += (num % 10) + '0';
        num /= 10;
    }
    reverse(s.begin(), s.end());
    out << s;
    return out;
}

void checkFractionsEqual() {
    __int128 a, b, c, d;
    cin >> a >> b >> c >> d;

    // Check if a * d == b * c using __int128
    __int128 left = a * d;
    __int128 right = b * c;

    cout << ((left == right) ? "Equal" : "Not Equal") << '\n';
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        checkFractionsEqual();
    }

    return 0;
}
