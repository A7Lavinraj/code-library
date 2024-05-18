#include <vector>
using namespace std;

struct segtree {
  // TODO: check if input overflows int.
  vector<int> tree;

  segtree(int N = 200200) { tree.resize(4 * N); }

  void build(vector<int> &container, int node, int low, int high) {
    if (low == high)
      tree[node] = container[low];
    else {
      int mid = low + (high - low) / 2;

      build(container, 2 * node, low, mid);
      build(container, 2 * node + 1, mid + 1, high);

      tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
  }

  int query(int node, int begin, int end, int low, int high) {
    if (low > high)
      return 0;

    if (low == begin && high == end)
      return tree[node];

    int mid = begin + (end - begin) / 2;

    return query(2 * node, begin, mid, low, min(high, mid)) +
           query(2 * node + 1, mid + 1, end, max(low, mid + 1), high);
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

      tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
  }
};
