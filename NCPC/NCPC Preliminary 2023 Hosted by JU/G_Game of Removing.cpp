#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define Wrong                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int main()
{
    Wrong;
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        ll n;
        cin >> n;
        vector<ll> v(n), p(n);
        for (ll i = 0; i < n; i++)
            cin >> v[i];
        for (ll i = 0; i < n; i++)
            cin >> p[i];
        ll cnt = 0;
        for (ll i = n - 1, j = n - 1; i >= 0;)
        {
            if (v[i] == p[j])
            {
                cnt++;
                i--;
                j--;
            }
            else
                i--;
        }
        // cout << cnt << '\n';
        ll j = 0;
        for (ll i = 0; i < n; i++)
        {
            for (; j < n; j++)
            {
                if (p[i] == v[j])
                {
                    // cout << i << " " << j << '\n';
                    // cout << "Dhukche" << '\n';
                    ll sum = 0;
                    for (ll k = n - 1, l = n - 1; k > j; k--)
                    {
                        if (v[k] == p[l])
                        {
                            sum++;
                            l--;
                        }
                    }
                    cnt = max(cnt, sum + i + 1);
                    j++;
                    break;
                }
            }
        }
        cout << n - cnt << '\n';
    }
    return 0;
}