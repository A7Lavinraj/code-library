#include <climits>
#include <functional>
#include <iostream>
#include <vector>

template <typename T> struct segment_tree {
public:
  segment_tree(std::vector<T> &data) {
    N = data.size();
    tree.resize(N * 4);
    identity = 0;
    operation = [](T a, T b) { return a + b; };
    build(data, 0, 0, N - 1);
  }

  segment_tree(std::vector<T> &data, T identity, std::function<T(T, T)> operation) {
    N = data.size();
    tree.resize(N * 4);
    this->identity = identity;
    this->operation = operation;
    build(data, 0, 0, N - 1);
  }

  T query(int L, int R) { return _query(0, 0, N - 1, L, R); }

  void update(int index, T updated_value) {
    _update(0, 0, N - 1, index, updated_value);
  }

private:
  int N;
  T identity;
  std::vector<T> tree;
  std::function<T(T, T)> operation;

  void build(std::vector<T> &data, int node, int begin, int end) {
    if (begin == end) {
      tree[node] = data[begin];
    } else {
      int mid = begin + (end - begin) / 2;
      build(data, 2 * node + 1, begin, mid);
      build(data, 2 * node + 2, mid + 1, end);
      tree[node] = operation(tree[2 * node + 1], tree[2 * node + 2]);
    }
  }

  T _query(int node, int begin, int end, int L, int R) {
    if (R < begin || L > end)
      return identity;

    if (L <= begin && end <= R)
      return tree[node];

    int mid = begin + (end - begin) / 2;
    T sub_L = _query(2 * node + 1, begin, mid, L, R);
    T sub_R = _query(2 * node + 2, mid + 1, end, L, R);
    return operation(sub_L, sub_R);
  }

  void _update(int node, int begin, int end, int index, T updated_value) {
    if (begin == end) {
      tree[node] = updated_value;
    } else {
      int mid = begin + (end - begin) / 2;

      if (index <= mid)
        _update(2 * node + 1, begin, mid, index, updated_value);
      else
        _update(2 * node + 2, mid + 1, end, index, updated_value);

      tree[node] = operation(tree[2 * node + 1], tree[2 * node + 2]);
    }
  }
};

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  segment_tree<int> tree(v, 0, [](int a, int b) { return a + b; });
  std::cout << tree.query(0, 3) << '\n';
  return 0;
}
