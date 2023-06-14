#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp(100, vector<int>(100, -1));

int knapsack(int index, int remaining_weight, vector<int>& weights, vector<int>& values) {
  /* Base conditions:
   * 1. When knapsack is full.
   * 2. When items are finished.
   */

  if (remaining_weight == 0) return 0;
  if (index < 0) return 0;
  if (dp[index][remaining_weight] != -1) return dp[index][remaining_weight];

  // Not choose
  int ans = knapsack(index - 1, remaining_weight, weights, values);

  // Choose if knapsack has enough space
  if (remaining_weight - weights[index] >= 0)
    ans = max(ans, knapsack(index - 1, remaining_weight - weights[index], weights, values) + values[index]);

  return dp[index][remaining_weight] = ans;
}

int main() {
  int n, w;
  cin >> n >> w;

  vector<int> weights(n), values(n);

  for (int i = 0; i < n; ++i) {
    cin >> weights[i] >> values[i];
  }

  cout << knapsack(n - 1, w, weights, values) << '\n';
  return 0;
}
