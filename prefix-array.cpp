#include<iostream>
#include<vector>
using namespace std;

template<typename T>
vector<T> prefix(vector<T> normal_array) {
  vector<T> prefix_array((int)normal_array.size() + 1);
  for (int i = 1; i <= (int)normal_array.size(); i++) {
    prefix_array[i] = prefix_array[i - 1] + normal_array[i - 1]; 
  }
  return prefix_array;
}

template <typename T>
void vector_out(vector<T> output) {
  for (T iterator : output) {
    cout << iterator << " ";
  }
  cout << "\n";
}

int main() {
  vector<int> v = {1, 2, 3, 4, 5};
  v = prefix(v);
  vector_out(v);
  return 0;
}
