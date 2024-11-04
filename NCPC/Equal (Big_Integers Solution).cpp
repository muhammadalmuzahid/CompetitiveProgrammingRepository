#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

class BigInt {
    string digits;
public:
    BigInt(unsigned long long n = 0) {
        do {
            digits.push_back(n % 10 + '0');
            n /= 10;
        } while (n);
    }
    
    BigInt(string &s) {
        digits = "";
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            if (!isdigit(s[i])) throw("ERROR");
            digits.push_back(s[i] - '0');
        }
    }

    BigInt(const char *s) {
        digits = "";
        for (int i = strlen(s) - 1; i >= 0; i--) {
            if (!isdigit(s[i])) throw("ERROR");
            digits.push_back(s[i] - '0');
        }
    }
    
    BigInt(BigInt &a) { digits = a.digits; }
    
    friend bool Null(const BigInt &);
    friend int Length(const BigInt &);
    int operator[](const int) const;

    BigInt &operator=(const BigInt &a) {
        digits = a.digits;
        return *this;
    }
    
    // Arithmetic Operators
    friend BigInt operator+(const BigInt &, const BigInt &);
    friend BigInt operator-(const BigInt &, const BigInt &);
    friend BigInt operator*(const BigInt &, const BigInt &);

    // Comparison Operators
    friend bool operator==(const BigInt &, const BigInt &);
    friend bool operator<(const BigInt &, const BigInt &);

    // I/O Operators
    friend ostream &operator<<(ostream &, const BigInt &);
    friend istream &operator>>(istream &, BigInt &);
};

// Comparison Operators
bool operator==(const BigInt &a, const BigInt &b) {
    return a.digits == b.digits;
}

bool operator<(const BigInt &a, const BigInt &b) {
    int n = Length(a), m = Length(b);
    if (n != m) return n < m;
    for (int i = n - 1; i >= 0; i--) {
        if (a.digits[i] != b.digits[i]) return a.digits[i] < b.digits[i];
    }
    return false;
}

// Arithmetic Operators
BigInt operator+(const BigInt &a, const BigInt &b) {
    BigInt result;
    int carry = 0;
    int n = Length(a), m = Length(b), len = max(n, m);
    for (int i = 0; i < len; i++) {
        int sum = carry;
        if (i < n) sum += a.digits[i];
        if (i < m) sum += b.digits[i];
        result.digits.push_back(sum % 10);
        carry = sum / 10;
    }
    if (carry) result.digits.push_back(carry);
    return result;
}

BigInt operator-(const BigInt &a, const BigInt &b) {
    if (a < b) throw("Underflow: Negative result");
    BigInt result;
    int borrow = 0, n = Length(a), m = Length(b);
    for (int i = 0; i < n; i++) {
        int sub = a.digits[i] - borrow;
        if (i < m) sub -= b.digits[i];
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else borrow = 0;
        result.digits.push_back(sub);
    }
    while (result.digits.size() > 1 && result.digits.back() == 0) result.digits.pop_back();
    return result;
}

BigInt operator*(const BigInt &a, const BigInt &b) {
    BigInt result;
    int n = Length(a), m = Length(b);
    result.digits.resize(n + m, 0);
    for (int i = 0; i < n; i++) {
        int carry = 0;
        for (int j = 0; j < m || carry; j++) {
            int product = result.digits[i + j] + a.digits[i] * (j < m ? b.digits[j] : 0) + carry;
            result.digits[i + j] = product % 10;
            carry = product / 10;
        }
    }
    while (result.digits.size() > 1 && result.digits.back() == 0) result.digits.pop_back();
    return result;
}

// Helper Functions
bool Null(const BigInt &a) {
    return a.digits.size() == 1 && a.digits[0] == '0';
}

int Length(const BigInt &a) {
    return a.digits.size();
}

// I/O Operators
ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.digits.size() - 1; i >= 0; i--) out << (short)a.digits[i];
    return out;
}

istream &operator>>(istream &in, BigInt &a) {
    string s;
    in >> s;
    a.digits.clear();
    for (int i = s.size() - 1; i >= 0; i--) {
        if (!isdigit(s[i])) throw("Invalid number format");
        a.digits.push_back(s[i] - '0');
    }
    return in;
}

void idea() {
    BigInt a, b, c, d; 
    cin >> a >> b >> c >> d;
    cout << ((a * d == b * c) ? "Equal" : "Not Equal") << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int C = 1; C <= T; C++) {
        // cout << "Case " << C << ": " << '\n';
        idea();
    }
    return 0;
}