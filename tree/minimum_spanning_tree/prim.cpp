#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> P;

vector<vector<P>> adj;

int prim(int n) {
  priority_queue<P, vector<P>, greater<P>> pq; // 最小ヒープと同義で常に最小の要素を取得できる
  vector<bool> in_MST(n, false);
  int mst_weight = 0;

  pq.push({ 0, 0 });
  while(!pq.empty()) {
    int weight = pq.top().first;
    int vertex = pq.top().second;
    pq.pop();

    if (in_MST[vertex]) continue;

    in_MST[vertex] = true;
    mst_weight += weight;

    for (auto& edge : adj[vertex]) {
      int w = edge.first;
      int v = edge.second;
      if (in_MST[v]) continue;

      pq.push({ w, v });
    }
  }

  return mst_weight;
}

int main() {
  int n = 4;
  adj.resize(n);
  adj[0].push_back({10, 1});
  adj[0].push_back({6, 2});
  adj[0].push_back({5, 3});
  adj[1].push_back({10, 0});
  adj[1].push_back({15, 3});
  adj[2].push_back({6, 0});
  adj[2].push_back({4, 3});
  adj[3].push_back({5, 0});
  adj[3].push_back({15, 1});
  adj[3].push_back({4, 2});

  int mst_weight = prim(n);
  cout << "Total weight of MST: " << mst_weight << endl;

  return 0;
}

