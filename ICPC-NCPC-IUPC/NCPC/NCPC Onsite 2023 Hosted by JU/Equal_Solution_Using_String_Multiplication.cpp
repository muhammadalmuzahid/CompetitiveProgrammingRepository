#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

// https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/
string multiply(string num1, string num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    return "0";

    vector<int> result(len1 + len2, 0);
    int i_n1 = 0; 
    int i_n2 = 0; 
    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0; 
      
        for (int j = len2 - 1; j >= 0; j--){
            int n2 = num2[j] - '0';
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            carry = sum/10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;
    if (i == -1)
    return "0";

    string s = "";
    while (i >= 0)
        s += std::to_string(result[i--]);
    return s;
}

void idea() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << ((multiply(a, d) == multiply(b, c)) ? "Equal" : "Not Equal") << '\n'; 
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