template <typename T> bool isPalindrome(T conatiner) {
  int low = 0, high = conatiner.size() - 1;

  while (low < high) {
    if (conatiner[low] != conatiner[high])
      return false;
    low++, high--;
  }

  return true;
}
