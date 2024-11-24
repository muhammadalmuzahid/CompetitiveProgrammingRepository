#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

vector <vector <int>> possible_cases = {
    {0, 3, 6},
    {0, 4, 4},
    {0, 6, 3},
    {1, 1, 6},
    {1, 2, 4},
    {1, 3, 4},
    {1, 4, 2},
    {1, 4, 3},
    {1, 6, 1},
    {2, 1, 4},
    {2, 2, 2},
    {2, 4, 1},
    {3, 0, 6},
    {3, 1, 4},
    {3, 3, 3},
    {3, 4, 1},
    {3, 6, 0},
    {4, 0, 4},
    {4, 1, 2},
    {4, 1, 3},
    {4, 2, 1},
    {4, 3, 1},
    {4, 4, 0},
    {6, 0, 3},
    {6, 1, 1},
    {6, 3, 0}
};

void idea() {

    vector <int> v(3);
    cin >> v[0] >> v[1] >> v[2];

    for(int i = 0; i < (int) possible_cases.size(); i++) {
        if(v == possible_cases[i]) {
            cout << "perfectus" << '\n';
            return;
        }
    }
    cout << "invalidum" << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int C = 1; C <= T; C++) {
        cout << "Case " << C << ": ";
        idea();
    }
    return 0;
}