#include <vector>

template <typename T, typename T_iterable> std::vector<std::pair<T, int>> run_length_encoding(T_iterable &items) {
  std::vector<std::pair<T, int>> encoding;
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
