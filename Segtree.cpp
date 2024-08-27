#include <cstdint>
#include <vector>

struct segtree {
  std::vector<int64_t> tree;

  segtree(int64_t N = int64_t(200200)) { tree.resize(int64_t(4) * N); }

  int64_t operation(int64_t a, int64_t b) { return a + b; }

  void build(std::vector<int64_t> &container, int64_t node, int64_t low,
             int64_t high) {
    if (low == high)
      tree[node] = container[low];
    else {
      int64_t mid = low + (high - low) / 2;

      build(container, 2 * node, low, mid);
      build(container, 2 * node + 1, mid + 1, high);

      tree[node] = operation(tree[2 * node], tree[2 * node + 1]);
    }
  }

  int64_t query(int64_t node, int64_t begin, int64_t end, int64_t low,
                int64_t high) {
    if (low > high)
      return 0;

    if (low == begin && high == end)
      return tree[node];

    int64_t mid = begin + (end - begin) / 2;

    return operation(
        query(2 * node, begin, mid, low, std::min(high, mid)),
        query(2 * node + 1, mid + 1, end, std::max(low, mid + 1), high));
  }

  void update(int64_t node, int64_t begin, int64_t end, int64_t index,
              int64_t value) {
    if (begin == end)
      tree[node] = value;
    else {
      int64_t mid = begin + (end - begin) / 2;

      if (index <= mid)
        update(2 * node, begin, mid, index, value);
      else
        update(2 * node + 1, mid + 1, end, index, value);

      tree[node] = operation(tree[2 * node], tree[2 * node + 1]);
    }
  }
};
