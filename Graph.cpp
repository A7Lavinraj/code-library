#include <set>
#include <vector>

struct Graph {
  const int INF = int(1e9); // NOTE: set INF for your convenience
  std::vector<std::vector<std::pair<int, int>>> edges;
  std::vector<int> dist;

  Graph(int size) {
    edges.resize(size);
    dist.resize(size, INF);
  }

  void add_edge(int u, int v, int w) { edges[u].push_back(std::make_pair(w, v)); }

  void dijkstra(int src) {
    std::set<std::pair<int, int>> queue;
    queue.insert(std::make_pair(0, src));
    dist[src] = 0;

    while (!queue.empty()) {
      std::pair<int, int> node = *queue.begin();
      queue.erase(queue.begin());

      for (std::pair<int, int> child : edges[node.second]) {
        int distance = dist[node.second] + child.first;

        if (distance < dist[child.second]) {
          dist[child.second] = distance;
          queue.insert(child);
        }
      }
    }
  }
};
