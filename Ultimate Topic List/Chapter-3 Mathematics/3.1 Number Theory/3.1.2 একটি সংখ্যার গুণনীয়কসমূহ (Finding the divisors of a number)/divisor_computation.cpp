#include <bits/stdc++.h>
using namespace std;

const int MAX_LIMIT = 1e7 + 3; 

// Store lists of divisors for all numbers from 1 to MAX_LIMIT
vector<vector<int>> divisorLists(MAX_LIMIT);

// Count of divisors for all numbers from 1 to MAX_LIMIT
vector<int> divisorCounts(MAX_LIMIT, 0);

void computeDivisors() {
    for (int num = 1; num < MAX_LIMIT; num++) {
        for (int multiple = num; multiple < MAX_LIMIT; multiple += num) {
            divisorLists[multiple].push_back(num); 
            divisorCounts[multiple]++;         
        }
    } // (O(N log N))
}

int main() {
    computeDivisors();
    int sampleNumber = 1234567;
    cout << "Divisors of " << sampleNumber << ": ";
    for (const auto& divisor : divisorLists[sampleNumber]) { cout << divisor << " "; }
    cout << "\n";
    cout << "Number of divisors of " << sampleNumber << ": " << divisorCounts[sampleNumber] << "\n";
    return 0;
}
