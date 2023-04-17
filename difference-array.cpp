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

    vector<int> get() {
      for (int i = 1; i <= (int)diff_array.size(); i++) {
        diff_array[i] += diff_array[i - 1];
      }
      diff_array.pop_back();
      return diff_array;
    }
};

template <typename T = int> void vector_out(vector<T> output) {
  for (T iterator : output) {
    cout << iterator << " ";
  }
  cout << "\n";
}

int main() {
  difference_array<int> arr(5);
  arr.change(1, 4, 2);
  vector_out(arr.get());
  return 0;
}
