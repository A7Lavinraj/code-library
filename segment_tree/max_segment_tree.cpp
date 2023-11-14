#include <bits/stdc++.h>
using namespace std;

struct Segement_tree {
  // TODO: check if input overflows int.
  const int N = 1e5;
  vector<int> tree;

  Segement_tree() {
    tree.assign(4 * N, 0);
  }

  void build(vector<int> &container, int node, int low, int high) {
    if (low == high)
      tree[node] = container[low];
    else {
      int mid = low + (high - low) / 2;

      build(container, 2 * node, low, mid);
      build(container, 2 * node + 1, mid + 1, high);

      tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
  }

  int query(int node, int begin, int end, int low, int high) {
    if (low > high)
      return INT_MIN;

    if (low == begin && high == end)
      return tree[node];

    int mid = begin + (end - begin) / 2;

    return max(query(2 * node, begin, mid, low, min(high, mid)), query(2 * node + 1, mid + 1, end, max(low, mid + 1), high));
  }

  void update(int node, int begin, int end, int index, int value) {
    if (begin == end)
      tree[node] = value;
    else {
      int mid = begin + (end - begin) / 2;

      if (index <= mid)
        update(2 * node, begin, mid, index, value);
      else 
        update(2 * node + 1, mid + 1, end, index, value);

      tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
  }
};

int main(void) {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Segement_tree tree;

  tree.build(arr, 1, 0, 9);

  cout << tree.query(1, 0, 9, 0, 2) << '\n';
  tree.update(1, 0, 9, 1, 10);
  cout << tree.query(1, 0, 9, 0, 2) << '\n';

  return 0;
}
