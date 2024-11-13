#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, key;
    cin >> n >> key;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = n - 1, mid, idx = -1;
    while (l <= r) {
        mid = l + (r - l) / 2; // Corrected calculation of mid to prevent overflow
        if (key == a[mid]) {
            idx = mid;
            break;
        } else if (key < a[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    if (idx == -1) {
        cout << "Element not found" << '\n';
    } else {
        cout << "Element found at index " << idx << '\n';
    }

    return 0;
}
