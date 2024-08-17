#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename T_iterable> vector<pair<T, int>> run_length_encoding(T_iterable &items) {
  vector<pair<T, int>> encoding;
  T character = items[0];
  int count = 0;

  for (char &item : items) {
    if (character == item) {
      count++;
    } else {
      encoding.emplace_back(character, count);
      count = 1;
      character = item;
    }
  }

  encoding.emplace_back(character, count);

  return encoding;
}

int main() {
  string s = "aadddkkklljj";
  auto encoding = run_length_encoding<char>(s);

  for (auto &x : encoding)
    cout << x.first << ": " << x.second << '\n';

  return 0;
}
