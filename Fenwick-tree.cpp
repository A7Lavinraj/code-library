#include <vector>

struct fenwick_tree {
  std::vector<int> tree;
  int n;

  fenwick_tree(int n) {
    this->n = n;
    tree.assign(n, 0);
  }

  fenwick_tree(std::vector<int> const &a) : fenwick_tree(a.size()) {
    for (size_t i = 0; i < a.size(); i++)
      update(i, a[i]);
  }

  int query(int index) {
    int result = 0;

    while (index > 0) {
      result += tree[index];
      index -= index & (-index);
    }

    return result;
  }

  void update(int index, int delta) {
    while (index < n) {
      tree[index] += delta;
      index = index | (index + 1);
    }
  }

  void update(int low, int high, int delta) {
    update(low, delta);
    update(high + 1, -delta);
  }
};
