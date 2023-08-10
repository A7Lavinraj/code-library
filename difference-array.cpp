#include <iostream>
#include <vector>
using namespace std;

template <typename T> class difference_array {
  public: 
    vector<int> diff_array;
    difference_array(int array_size) {
      diff_array = vector<int> (array_size + 1, 0);
    }

    void change(int from, int to, int value) {
      diff_array[from] += value;
      diff_array[to + 1] -= value;
    }

    vector<int> get_array() {
      diff_array.pop_back();
      return diff_array;
    }
};

template<typename T = int> vector<T> prefix(vector<T> normal_array, bool zero = false) {
  vector<T> prefix_array((int)normal_array.size() + 1);
  for (int i = 1; i <= (int)normal_array.size(); i++) {
    prefix_array[i] = prefix_array[i - 1] + normal_array[i - 1]; 
  }

  if (zero == false) prefix_array.erase(prefix_array.begin());
  return prefix_array;
}

template <typename T = int> void vector_out(vector<T> output) {
  for (T iterator : output) {
    cout << iterator << " ";
  }
  cout << "\n";
}

int main() {
  difference_array<int> arr(5);
  arr.change(0, 4, 1);
  vector_out(prefix(arr.get_array()));
  return 0;
}
