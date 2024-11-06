#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int  sieve_size  = (int) 1e3 + 7;
vector <int> save_primes;
vector <bool> is_prime(sieve_size, true);
void Eratosthenes_Sieve(){
    is_prime[0] = is_prime[1] = false;
    is_prime[2] = true;
    for (int i = 3; i * i <= sieve_size; i+=2) {
        if (is_prime[i]) {
            for (int j = i * i; j <= sieve_size; j += i + i)
                is_prime[j] = false;
        }
    }
    save_primes.push_back(2);
    for(int i = 3; i <= sieve_size; i+=2){
        if(is_prime[i])
            save_primes.push_back(i);
    }
}

void idea() {
    int n;
    cin >> n;
    int tg = n * n;

    vector <int> val;
    while(tg > 0) {
        int near_prime = 1;
        for(auto i : save_primes) {
            if(i <= tg) {
                near_prime = max(near_prime, i);
            }
            else {
                break;
            }
        }
        val.push_back(near_prime);
        tg -= near_prime;

    }


    vector <int> ans;
    for (int i = 0; i < (int)val.size(); i++) {
        int x = val[i];
        for(int j = 0; j < x; j++) {
            ans.push_back(val[i]);
        }
    }

    ll res[n + 3] [ n + 3];
    int idx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            res[i + 1][ j + 1] = ans[idx++];
        }
    }

    for(ll i = n; i >= 1; i--) {
        for(ll j = n; j >= 1; j--) {
            ll val = res[i][j];
            if(gcd(val, i) > 1 or gcd(val, j) > 1) {
                // need to swap
                bool found_place = false;
                for(int ii = 1; ii <= n; ii++) {
                    for(int jj = 1; jj <= n; jj++) {
                        if(gcd(val, ii) == 1 and gcd(val, jj) == 1) {
                            found_place = true;
                            swap(res[i][j], res[ii][jj]);
                            break;
                        }
                        if(found_place) {
                            break;
                        }
                    }
                    if(found_place) {
                        break;
                    }
                }
            }
        }
    }

    string answer[n + 3][n + 3];

    int mx_len = 0;
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            string s = to_string(res[i][j]);
            mx_len = max(mx_len, (int)s.size());
            answer[i][j] = s;
        }
    }

    // for (ll i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         string s = answer[i][j];
    //         if((int)s.size() < mx_len) {
    //             while((int)s.size() < mx_len) {
    //                 s = s + " ";
    //             }
    //         }
    //         answer[i][j] = s;
    //     }
    // }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << answer[i][j];
            if(j < n) {
                cout << " ";
            }
        }
        cout << '\n';
    }

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Eratosthenes_Sieve ();
    int T = 1;
    // cin >> T;
    for(int C = 1; C <= T; C++) {
        // cout << "Case " << C << ": " << '\n';
        idea();
    }
    return 0;
}