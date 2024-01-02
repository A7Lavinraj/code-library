#include <bits/stdc++.h>
using namespace std;

int64_t max_sum_with_k(vector<int64_t>& container, int64_t k) {
  int n = (int)container.size();
  vector<int> maxsum(n);
  int currmax = container[0];
  maxsum[0] = container[0];

  for (int i = 1; i < n; i++) {
    currmax = max(container[i], currmax + container[i]);
    maxsum[i] = currmax;
  }

  int sum_k = accumulate(container.begin(), container.begin() + k, int64_t(0));
  int result = sum_k;

  for (int i = k; i < n; i++) {
    sum_k += container[i] - container[i - k];
    result = max({result, sum_k, sum_k + maxsum[i - k]});
  }

  return result;
}

int main() {
  vector<int64_t> input = {1, -2, 2, -3};
  cout << max_sum_with_k(input, 2) << "\n";
  return 0;
}
