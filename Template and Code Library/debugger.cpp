#include <bits/stdc++.h>
using namespace std;

#define bug(x) debug(x, #x)

// Pair Input
template <typename X, typename Y>
istream &operator>>(istream &cin, pair<X, Y> &a) {
    return cin >> a.first >> a.second;
}

// Pair Output
template <typename X, typename Y>
ostream &operator<<(ostream &cout, const pair<X, Y> &a) {
    return cout << a.first << ' ' << a.second;
}

// Vector of Pairs Input
template <typename X, typename Y>
istream &operator>>(istream &cin, vector<pair<X, Y>> &vec) {
    for (auto &x : vec) cin >> x;
    return cin;
}

// Vector of Pairs Output
template <typename X, typename Y>
ostream &operator<<(ostream &cout, const vector<pair<X, Y>> &vec) {
    for (const auto &x : vec) cout << x << '\n';
    return cout;
}

// Tuple Input
template <typename X, typename Y, typename Z>
istream &operator>>(istream &cin, tuple<X, Y, Z> &a) {
    return cin >> get<0>(a) >> get<1>(a) >> get<2>(a);
}

// Tuple Output
template <typename X, typename Y, typename Z>
ostream &operator<<(ostream &cout, const tuple<X, Y, Z> &a) {
    return cout << '(' << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ')';
}

// Vector of Tuples Input
template <typename X, typename Y, typename Z>
istream &operator>>(istream &cin, vector<tuple<X, Y, Z>> &vec) {
    for (auto &t : vec) cin >> t;
    return cin;
}

// Vector of Tuples Output
template <typename X, typename Y, typename Z>
ostream &operator<<(ostream &cout, const vector<tuple<X, Y, Z>> &vec) {
    for (const auto &t : vec) cout << t << '\n';
    return cout;
}

// Vector Input
template <typename X>
istream &operator>>(istream &cin, vector<X> &a) {
    for (auto &x : a) cin >> x;
    return cin;
}

// Vector Output
template <typename X>
ostream &operator<<(ostream &cout, const vector<X> &a) {
    int n = a.size();
    if (n == 0) return cout;
    cout << a[0];
    for (int i = 1; i < n; i++) cout << ' ' << a[i];
    return cout;
}

// Matrix (Nested Vector) Input
template <typename X>
istream &operator>>(istream &cin, vector<vector<X>> &mat) {
    for (auto &row : mat) {
        for (auto &elem : row) {
            cin >> elem;
        }
    }
    return cin;
}

// Matrix (Nested Vector) Output
template <typename X>
ostream &operator<<(ostream &cout, const vector<vector<X>> &mat) {
    for (const auto &row : mat) {
        for (const auto &elem : row) {
            cout << elem << ' ';
        }
        cout << '\n';
    }
    return cout;
}

// Map Input
template <typename X, typename Y>
istream &operator>>(istream &cin, map<X, Y> &m) {
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        X key;
        Y value;
        cin >> key >> value;
        m[key] = value;
    }
    return cin;
}

// Map Output
template <typename X, typename Y>
ostream &operator<<(ostream &cout, const map<X, Y> &m) {
    for (const auto &[x, y] : m) cout << x << ' ' << y << '\n';
    return cout;
}

// Set Input
template <typename X>
istream &operator>>(istream &cin, set<X> &s) {
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        X value;
        cin >> value;
        s.insert(value);
    }
    return cin;
}

// Set Output
template <typename X>
ostream &operator<<(ostream &cout, const set<X> &s) {
    for (const auto &x : s) cout << x << ' ';
    return cout;
}

// Stack Input
template <typename X>
istream &operator>>(istream &cin, stack<X> &s) {
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        X value;
        cin >> value;
        s.push(value);
    }
    return cin;
}

// Stack Output
template <typename X>
ostream &operator<<(ostream &cout, stack<X> s) {
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    return cout;
}

// Queue Input
template <typename X>
istream &operator>>(istream &cin, queue<X> &q) {
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        X value;
        cin >> value;
        q.push(value);
    }
    return cin;
}

// Queue Output
template <typename X>
ostream &operator<<(ostream &cout, queue<X> q) {
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
    return cout;
}

// Deque Input
template <typename X>
istream &operator>>(istream &cin, deque<X> &dq) {
    for (auto &x : dq) cin >> x;
    return cin;
}

// Deque Output
template <typename X>
ostream &operator<<(ostream &cout, const deque<X> &dq) {
    for (const auto &x : dq) cout << x << ' ';
    return cout;
}

// Priority Queue Input
template <typename X>
istream &operator>>(istream &cin, priority_queue<X> &pq) {
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        X value;
        cin >> value;
        pq.push(value);
    }
    return cin;
}

// Priority Queue Output
template <typename X>
ostream &operator<<(ostream &cout, priority_queue<X> pq) {
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    return cout;
}

// Debugger: Finding Bug
template <typename X>
void debug(const X &x, const string &name) {
    cout << name << " = " << x << '\n';
}

void Run_Time() {
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Code Execution Time: " << elapsed.count() << " seconds.\n";
}

int main() {
    int num = 42;
    double pi = 3.14159;
    string msg = "Hello, World!";
    vector <int> vec = {1, 2, 3, 4, 5};

    bug(num);   // Output: num = 42
    bug(pi);    // Output: pi = 3.14159
    bug(msg);   // Output: msg = Hello, World!
    bug(vec);   // Output: vec = 1 2 3 4 5

    return 0;
}
