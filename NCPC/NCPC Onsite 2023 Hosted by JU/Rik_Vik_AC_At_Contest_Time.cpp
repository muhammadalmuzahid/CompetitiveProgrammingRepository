// Accepted code at onsite contest time
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
void optimize()
{
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
}
const ll mod=1e9+7;
vector<ll>v(1000010);
ll binExp(ll Base,ll Exponent)
{
    ll Result=1LL;
    Base=Base%mod;
    if(Base==0)
        return 0;
    while(Exponent>0)
    {
        if(Exponent&1)
            Result=(Result*Base)%mod;
        Exponent=Exponent>>1;
        Base=(Base*Base)%mod;
    }
    return Result;
}
int main()
{
    optimize();
    ll ans=1;
    for(ll i=1; i<=1000000; i++)
    {
        ans=(ans*i)%mod;
        v[i]=ans;
    }
    int test;
    cin >> test;
    for(int Case = 1; Case <= test; Case++)
    {
        ll s,n,m;
        cin>>s>>n>>m;
        ll column=s/n;
        ll column_baki=m-column;
        ll last_column=(column-1)*n;

        ll sum=v[s-last_column];
        ll pow=binExp(sum,column_baki);
        ll final=(pow*v[s])%mod;
        cout<<final<<'\n';

    }
    return 0;
}
