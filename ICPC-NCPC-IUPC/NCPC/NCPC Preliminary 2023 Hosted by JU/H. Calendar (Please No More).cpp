// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define endl               '\n'
#define yes                cout << "YES" << endl
#define no                 cout << "NO" << endl
#define show(x)            cout << #x << " : " << x << endl
#define showtwo(x, y)      cout << #x << " : " << x << " " << #y << " : " << y << endl
#define all(a)             (a).begin(),(a).end()
#define rall(a)            (a).rbegin(),(a).rend()
#define toLowerCase(s)     transform(s.begin(), s.end(), s.begin(), ::tolower);
#define toUpperCase(s)     transform(s.begin(), s.end(), s.begin(), ::toupper);
#define pb                 push_back
#define pf                 push_front
#define mp                 make_pair
#define ff                 first
#define ss                 second
#define mem(a, b)          memset(a, b, sizeof(a) )
#define input_arr(vec)     for(auto &&it:vec) {cin >> it;}
#define display_arr(vec)   for (auto &&it : vec){cout << it << " ";} cout << endl;
#define files()            freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
#define fraction()         cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return abs(a) * ( abs(b) / gcd ( a, b ) ); }

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

template < typename F, typename S >ostream& operator << ( ostream& os, const pair< F, S > & p ) {return os << "(" << p.first << ", " << p.second << ")";}
template < typename T >ostream &operator << ( ostream & os, const vector< T > &v ) {os << "{";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "}";}
template < typename T >ostream &operator << ( ostream & os, const set< T > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "]";}
template < typename T >ostream &operator << ( ostream & os, const multiset< T > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "]";}
template < typename F, typename S >ostream &operator << ( ostream & os, const map< F, S > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << it -> first << " = " << it -> second ;}return os << "]";}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

void faltu () {cerr << endl;}
template <typename T>void faltu( T a[], int n ) {for(int i = 0; i < n; ++i) cerr << a[i] << ' ';cerr << endl;}
template <typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}

/*---------------------------------------------------------------------------------------------------------------*/
bool leapYear(int year)
{
    if (year % 400 == 0) {
        return true;
    }
    else if (year % 100 == 0) {
        return false;
    }
    else if (year % 4 == 0) {
        return true;
    }
    else {
        return false;
    }
}

void dash() {
    cout << "|---------------------------|" << endl;
}

void solve()
{
    int day, mon, year;
    char ch;
    string str;
    cin >> day >> ch >> mon >> ch >> year >> str;

    int start;
    if (str == "Sun") start = 1;
    if (str == "Mon") start = 2;
    if (str == "Tue") start = 3;
    if (str == "Wed") start = 4;
    if (str == "Thu") start = 5;
    if (str == "Fri") start = 6;
    if (str == "Sat") start = 7;

    dash();
    cout << "|Sun|Mon|Tue|Wed|Thu|Fri|Sat|" << endl;
    dash();

    vi month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (leapYear(year) and mon == 2) month[2] = 29;
    vi arr(35, 0);
    int temp = start;
    for (int i = day; i <= month[mon]; i++)
    {
        arr[i] = temp;
        temp++;
        if (temp == 8) temp = 1;
    }
    temp = start;
    for (int i = day; i >= 1; i--)
    {
        arr[i] = temp;
        temp--;
        if (temp == 0) temp = 7;
    }

    vector<string> ans;

    // First Row
    string row = ""; row += '|';
    for (int i = 1; i < arr[1]; i++)
        row += " - |";

    int first = 1;
    for (int i = arr[first]; i <= 7; i++)
    {
        row += "  ";
        row += (first + '0');
        row += '|';
        first++;
    }

    ans.push_back(row);

    // Second Row
    row.clear();
    row = "|";
    temp = first;
    for (int i = first; i < temp + 7; i++)
    {
        string val = to_string(first);
        if ( val.size() == 1) row += "  ";
        else row += " ";

        row += val;
        row += '|';
        first++;
    }
    ans.push_back(row);

    // Third Row
    row.clear();
    row = "|";
    temp = first;
    for (int i = first; i < temp + 7; i++)
    {
        string val = to_string(first);
        if ( val.size() == 1) row += "  ";
        else row += " ";

        row += val;
        row += '|';
        first++;
    }
    ans.push_back(row);

    // Fourth Row
    row.clear();
    row = "|";
    temp = first;
    for (int i = first; i < temp + 7; i++)
    {
        string val = to_string(first);
        if ( val.size() == 1) row += "  ";
        else row += " ";

        row += val;
        row += '|';
        first++;
    }
    ans.push_back(row);

    // Fifth Row
    row.clear(); row = "|";
    temp = first;
    int cnt = 1;
    while (first <= month[mon])
    {
        if (cnt <= 7) {
            string val = to_string(first);
            if ( val.size() == 1) row += "  ";
            else row += " ";

            row += val;
            row += '|';
            first++;
            cnt++;
        }
        else break;
    }
    cnt--;
    for (int i = cnt; i < 7; i++) {
        row += " - |";
    }
    ans.push_back(row);


    // Missing Value
    int mis = month[mon] - first + 1;
    int idx = 1;
    row.clear();
    for (int i = 0; i < mis; i++)
    {
        ans[0].erase(idx, 4);
        string val = to_string(first);
        if ( val.size() == 1) row += "  ";
        else row += " ";

        row += val;
        row += '|';
        first++;
        ans[0].insert(idx, row);
        idx += 4;
        row.clear();
    }

    for (auto &&str : ans)
    {
        cout << str << endl;
        dash();
    }
    cout << endl;
}

int main(void)
{
    efficient();
    // clock_t z = clock();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }

    // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC); // the run time printed here is in seconds
    return 0;
}