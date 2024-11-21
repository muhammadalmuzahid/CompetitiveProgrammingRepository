// MH_Nazmul
// Let it be as simple

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define nl cout << "\n"
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define f(a, b, c) for (int a = b; a < c; a++)
#define cin(vec, n) \
    f(i, 0, n) { cin >> vec[i]; }
#define int long long
const int N = 2e5 + 10;
const int M = 1e9 + 7;

void solve(void)
{
    int n, d;
    cin >> n >> d;
    vector<int> laser(n + 1, 1);
    vector<pair<int, int>> points(d + 1);
    for (int i = 0; i < d; i++)
    {
        cin >> points[i].first >> points[i].second;
    }
    int cnt = 0;
    for (int i = 0; i < d; i++)
    {
        for (int j = i + 1; j < d; j++)
        {
            int x1_x2 = points[i].first - points[j].first;
            int y1_y2 = points[i].second - points[j].second;
            int lob = (-points[i].second) * (x1_x2);
            if (y1_y2 != 0 and lob % y1_y2 == 0)
            {
                int x = (lob / y1_y2) + points[i].first;
                if (x < 1 || x > n)
                    continue;
                cnt = 0;
                for (int k = 0; k < d; k++)
                {
                    if ((points[k].first - points[i].first) * y1_y2 == (points[k].second - points[i].second) * x1_x2)
                    {
                        cnt++;
                    }
                }
                laser[x] = max(laser[x], cnt);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << laser[i] << " ";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}