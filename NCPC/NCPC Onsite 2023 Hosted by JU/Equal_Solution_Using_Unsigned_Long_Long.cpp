// This is first accepted code in NCPC Onsite Hosted By JU
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
void optimize(){
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
}
//cout << "Case " <<test<<": "<<
void approach(int test){

    unsigned long long a,b,c,d;
    cin>>a>>b>>c>>d;
    ll x=__gcd(a,b);
    a/=x;
    b/=x;
    ll y=__gcd(c,d);
    c/=y;
    d/=y;
    if(a==c&&b==d)
        cout<<"Equal"<<'\n';
    else
        cout<<"Not Equal"<<'\n';
}

int main(){
    optimize();
    int test;
    cin >> test;
    for(int Case = 1; Case <= test; Case++){
        approach(Case);
    }
    return 0;
}