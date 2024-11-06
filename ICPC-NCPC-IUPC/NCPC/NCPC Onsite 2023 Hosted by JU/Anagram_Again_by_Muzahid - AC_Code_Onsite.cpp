#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
void optimize()
{
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    optimize();
    int test;
    cin >> test;
    for(int Case = 1; Case <= test; Case++)
    {
        int n;
        cin >> n;
        vector<string>v;
        for(ll i=0; i<n; i++)
        {
            string r;
            cin>>r;
            sort(r.begin(),r.end());
            v.push_back(r);
        }
        ll q;
        cin>>q;
        vector<ll>a;
        while(q--)
        {
            string s;
            cin>>s;
            sort(s.begin(),s.end());
            ll cnt=0,ans=0;
            for(ll i=0; i<n; i++)
            {
                ll k=0,j=0;
                for(;k<s.size();k++)
                {
                    if(s[k]==v[i][j])
                    {
                        cnt++;
                        j++;
                    }
                    if(cnt==v[i].size())
                        break;
                }
                if(cnt==v[i].size())
                    ans++;
                cnt=0;

            }
            a.push_back(ans);
        }
        cout << "Case " << Case << ":"<<'\n';
        for(auto it:a)
            cout<<it<<'\n';

    }
    return 0;
}