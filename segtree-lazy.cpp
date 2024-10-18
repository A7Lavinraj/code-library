#include <climits>
#include <functional>
#include <iostream>
#include <vector>

template <typename T> struct segment_tree {
public:
  segment_tree(std::vector<T> &data) {
    N = data.size();
    tree.resize(N * 4);
    lazy.resize(N * 4, 0);
    identity = 0;
    operation = [](T a, T b) -> T { return a + b; };
    apply_update = [](T a, T b, int len) -> T { return a + b * len; };
    build(data, 0, 0, N - 1);
  }

  segment_tree(std::vector<T> &data, T identity,
               std::function<T(T, T)> operation,
               std::function<T(T, T, int)> apply_update) {
    N = data.size();
    tree.resize(N * 4);
    lazy.resize(N * 4, identity);
    this->identity = identity;
    this->operation = operation;
    this->apply_update = apply_update;
    build(data, 0, 0, N - 1);
  }

  T query(int L, int R) { return _query(0, 0, N - 1, L, R); }

  void update(int L, int R, T update_value) {
    _update(0, 0, N - 1, L, R, update_value);
  }

private:
  int N;
  T identity;
  std::vector<T> tree, lazy;
  std::function<T(T, T)> operation;
  std::function<T(T, T, int)> apply_update;

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

  void propagate(int node, int begin, int end) {
    if (lazy[node] != identity) {
      tree[node] = apply_update(tree[node], lazy[node], end - begin + 1);

      if (begin != end) {
        lazy[2 * node + 1] = operation(lazy[2 * node + 1], lazy[node]);
        lazy[2 * node + 2] = operation(lazy[2 * node + 2], lazy[node]);
      }

      lazy[node] = identity;
    }
  }

  T _query(int node, int begin, int end, int L, int R) {
    propagate(node, begin, end);

    if (R < begin || L > end)
      return identity;

    if (L <= begin && end <= R)
      return tree[node];

    int mid = begin + (end - begin) / 2;
    T sub_L = _query(2 * node + 1, begin, mid, L, R);
    T sub_R = _query(2 * node + 2, mid + 1, end, L, R);
    return operation(sub_L, sub_R);
  }

  void _update(int node, int begin, int end, int L, int R, T update_value) {
    propagate(node, begin, end);

    if (R < begin || L > end)
      return;

    if (L <= begin && end <= R) {
      tree[node] = apply_update(tree[node], update_value, end - begin + 1);

      if (begin != end) {
        lazy[2 * node + 1] = operation(lazy[2 * node + 1], update_value);
        lazy[2 * node + 2] = operation(lazy[2 * node + 2], update_value);
      }

      return;
    }

    int mid = begin + (end - begin) / 2;
    _update(2 * node + 1, begin, mid, L, R, update_value);
    _update(2 * node + 2, mid + 1, end, L, R, update_value);
    tree[node] = operation(tree[2 * node + 1], tree[2 * node + 2]);
  }
};

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};

  segment_tree tree(v);

  std::cout << tree.query(0, 4) << '\n';

  tree.update(1, 3, 1);
  std::cout << tree.query(0, 4) << '\n';

  return 0;
}
