#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int max_subarray_sum(vector<int>& arr) {
  int max_so_far = INT_MIN, max_ending_here = 0;
  
  for (int i = 0; i < (int)arr.size(); i++) {
    max_ending_here = max_ending_here + arr[i];
    max_so_far = max(max_so_far, max_ending_here);
    max_ending_here = max(max_ending_here, 0);
  }

  return max_so_far;
}

int main() {
  vector<int> arr = { -2, -3, 4, -1, -2, 1, 5, -3 };
  cout << max_subarray_sum(arr) << '\n';
  return 0;
}
