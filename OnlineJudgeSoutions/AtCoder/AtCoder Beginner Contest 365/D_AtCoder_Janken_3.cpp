#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') a[i] = 0;
		if (s[i] == 'P') a[i] = 1;
		if (s[i] == 'S') a[i] = 2;
	}

	vector <vector <int>> opt(n + 1, vector <int> (3, -INT_MAX));
	for (int i = 0; i < 3; i++) {
		opt[0][i] = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j != k) { // previous move != current move
					if (k == (a[i] + 1) % 3) { // winning move
						opt[i + 1][k] = max(opt[i + 1][k], opt[i][j] + 1);
					}
					else if (k != (a[i] + 2) % 3) { // not losing move 
						opt[i + 1][k] = max(opt[i + 1][k], opt[i][j]);
					}
				}
			}
		}
	}

	int ans = *max_element(opt[n].begin(), opt[n].end());
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	// cin >> T;
	for(int C = 1; C <= T; C++) {
		// cout << "Case " << C << ": " << '\n';
		idea();
	}
	return 0;
}