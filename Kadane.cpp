#include <algorithm>
#include <climits>
#include <cstdint>
#include <numeric>
#include <vector>
using namespace std;

int max_subarray_sum(vector<int> &arr) {
  int max_so_far = INT_MIN, max_ending_here = 0;

  for (int i = 0; i < (int)arr.size(); i++) {
    max_ending_here = max_ending_here + arr[i];
    max_so_far = max(max_so_far, max_ending_here);
    max_ending_here = max(max_ending_here, 0);
  }

  return max_so_far;
}

int64_t max_sum_with_k(vector<int64_t> &container, int64_t k) {
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
