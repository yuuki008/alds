#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
  int u, v, weight;
  bool operator<(const Edge& other) const {
    return weight < other.weight;
  }
};

struct UnionFind {
  vector<int> parent, rank;

  UnionFind(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  int find(int u) {
    if (u != parent[u]) {
      parent[u] = find(parent[u]);
    }
    return parent[u];
  }

  void unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
      if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
      } else if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
      } else {
        parent[rootV] = rootU;
        ++rank[rootU];
      }
    }
  }
};

int kruskal(int n, vector<Edge>& edges) {
  /* 1. エッジを昇順にソート */
  sort(edges.begin(), edges.end());
  UnionFind uf(n);
  int mst_weight = 0;

  /* 2. 重みが小さい順にエッジを選び、サイクルが形成されない様にエッジを追加 */
  for (const auto& edge : edges) {
    if (uf.find(edge.u) != uf.find(edge.v)) {
      uf.unite(edge.u, edge.v);
      mst_weight += edge.weight;
      cout << "Edge: " << edge.u << " - " << edge.v << " weight: " << edge.weight << endl;
    }
  }

  return mst_weight;
}

int main() {
  int n = 4;
  vector<Edge> edges = {
    {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
  };

  int mst_weight = kruskal(n, edges);
  cout << "Total weight of MST: " << mst_weight << endl;

  return 0;
}

