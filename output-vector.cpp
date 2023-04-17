#include<iostream>
#include<vector>
using namespace std;

template <typename T>
void vector_out(vector<T> output) {
  for (T iterator : output) {
    cout << iterator << " ";
  }
  cout << "\n";
}

int main() {
  vector<double> vec = {1.2, 2.4, 4, 4, 5};
  vector_out(vec);
  return 0;
}
