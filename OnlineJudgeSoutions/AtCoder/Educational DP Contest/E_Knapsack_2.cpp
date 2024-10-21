#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

const int mx = (int) 1e5 + 5; // Maximum sum of values that can be targeted

int n, capacity; // Variables for number of items and the capacity of the knapsack
int w[mx], profit[mx]; // Arrays to store weights and profits of items
ll dp[103][mx]; // DP table, dp[i][v] = minimum weight to achieve value 'v' using items up to index i

// Knapsack function to calculate minimum weight to achieve a certain value
ll knapsack(int idx, int value_left) {
    // Base case: If no value is left to achieve, we need zero weight
    if(value_left == 0) return 0;

    // Base case: If we have gone through all items, return a large number (infeasible)
    if(idx > n) return (ll) 1e15;

    // Memoization: If the answer for this state has already been calculated, return it
    if(dp[idx][value_left] != -1) return dp[idx][value_left];

    // Recursive case: Do not take the current item
    ll not_take = knapsack(idx + 1, value_left);

    // Initialize the answer with the "not take" case
    ll ans = not_take;

    // Recursive case: Take the current item if value can still be achieved
    if (value_left - profit[idx] >= 0) {
        ll take = w[idx] + knapsack(idx + 1, value_left - profit[idx]); // Include item's weight
        ans = min(ans, take); // Choose the minimum weight between taking and not taking the item
    }

    // Store the result and return
    return dp[idx][value_left] = ans;
}

/*
Main idea:
- We want to maximize the total profit we can carry with the given weight capacity.
- Instead of minimizing the weight for a given target value, we reverse and iterate over possible values,
  checking which is the maximum value that can be achieved within the knapsack's capacity.
*/

void idea() {
    // Input number of items and the knapsack capacity
    cin >> n >> capacity;
    // Input weights and profits for each item
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> profit[i];
    }
    // Initialize DP table with -1 for memoization
    memset(dp, -1, sizeof(dp));

    // Iterate over possible profits (from maximum down to 0)
    for(int cur_value = 1e5 + 5; cur_value >= 0; cur_value--) {
        // Find the minimum weight needed to achieve this value
        ll current_weight = knapsack(1, cur_value);
        
        // If the weight required to achieve this value is within the capacity, print the value and stop
        if(current_weight <= capacity) {
            cout << cur_value << '\n';
            break;
        }
    }
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