#include <cstdint>
#include <vector>
using namespace std;

struct segtree {
  vector<int> tree, lazy;

  segtree(int N = 200200) {
    tree.resize(4 * N);
    lazy.resize(4 * N);
  }

  int operation(int a, int b) { return a * b; }

  void build(vector<int> &container, int node, int begin, int end) {
    if (begin == end)
      tree[node] = container[begin];
    else {
      int mid = begin + (end - begin) / 2;

      build(container, 2 * node, begin, mid);
      build(container, 2 * node + 1, mid + 1, end);

      tree[node] = operation(tree[2 * node], tree[2 * node + 1]);
    }
  }

  int64_t query(int node, int begin, int end, int low, int high) {
    if (lazy[node] != 0) {
      tree[node] = operation(tree[node], (end - begin + 1) * lazy[node]);

      if (begin != end) {
        lazy[2 * node] = operation(lazy[2 * node], lazy[node]);
        lazy[2 * node + 1] = operation(lazy[2 * node + 1], lazy[node]);
      }

      lazy[node] = 1;
    }

    if (end < low || begin > high)
      return 1;

    if ((low <= begin) && (end <= high))
      return tree[node];

    int mid = begin + (end - begin) / 2;

    return operation(query(2 * node, begin, mid, low, high),
                     query(2 * node + 1, mid + 1, end, low, high) + int64_t(0));
  }

  void update(int node, int begin, int end, int low, int high, int value) {
    if (lazy[node] != 0) {
      tree[node] = operation(tree[node], (end - begin + 1) * lazy[node]);

      if (begin != end) {
        lazy[2 * node] = operation(lazy[2 * node], lazy[node]);
        lazy[2 * node + 1] = operation(lazy[2 * node + 1], lazy[node]);
      }

      lazy[node] = 1;
    }

    if ((end < low) || (begin > high))
      return;

    if (begin >= low && end <= high) {
      tree[node] = operation(tree[node], (end - begin + 1) * value);

      if (begin != end) {
        lazy[2 * node] = operation(lazy[2 * node], value);
        lazy[2 * node + 1] = operation(lazy[2 * node + 1], value);
      }
    } else {
      int mid = begin + (end - begin) / 2;

      update(2 * node, begin, mid, low, high, value);
      update(2 * node + 1, mid + 1, end, low, high, value);

      tree[node] = operation(tree[2 * node], tree[2 * node + 1]);
    }
  }
};
