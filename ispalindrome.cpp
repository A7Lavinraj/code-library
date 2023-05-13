#include <iostream>
#include <vector>
using namespace std;

template<typename T> bool isPalindrome(T conatiner) {
  int low = 0, high = conatiner.size() - 1;

  while(low < high) {
    if (conatiner[low] != conatiner[high]) return false;
    low++, high--;
  }

  return true;
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  cout << (isPalindrome(v) ? "True" : "False") << '\n';
  return 0;
}
