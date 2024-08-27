#include <cassert>
#include <vector>

struct DSU {
private:
  int _n;
  std::vector<int> parent, size;

public:
  DSU() : _n(0) {}
  DSU(int n) : _n(n) {
    parent.resize(_n, -1);
    size.resize(_n, -1);
  }

  void add(int x) {
    parent[x] = x;
    size[x] = 1;
  }

  int leader(int x) {
    assert(0 <= x && x < _n);

    if (parent[x] == x)
      return x;

    return parent[x] = leader(parent[x]);
  }

  int merge(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);

    if (x == y)
      return x;

    if (parent[x] < parent[y])
      std::swap(x, y);

    size[x] += size[y];
    parent[y] = x;

    return x;
  }

  bool same(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }
};
