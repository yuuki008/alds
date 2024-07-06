#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/* Depth First Search (DFS) */
/* d = 発見時刻 */
/* f = 探索完了時刻 */

/* INPUT */
/* 6 */
/* 1 2 2 4 */
/* 2 1 5 */
/* 3 2 5 6 */
/* 4 0 */
/* 5 1 4 */
/* 6 1 6 */

/* GOAL    */
/* 1  1  8 */
/* 2  2  7 */
/* 3  9 12 */
/* 4  4  5 */
/* 5  3  6 */
/* 6 10 11 */

int dfs(int key, int time, vector<vector<int>> A, vector<int> &d,
        vector<int> &h) {
  if (d[key] != -1) return time;

  time++;
  d[key] = time;

  for (int i = 0; i < A[key].size(); i++) {
    time = dfs(A[key][i], time, A, d, h);
  }

  time++;
  h[key] = time;

  return time;
}

int main() {
  /* int n = 6; */
  /* vector<vector<int>> A = {{1, 3}, {4}, {4, 5}, {}, {3}, {5}}; */

  int n;
  cin >> n;

  vector<vector<int>> A(n);
  for(int i=0; i<n; i++) {
    int u, k;
    cin >> u >> k;

    for (int j=0; j<k; j++) {
      int v;
      cin >> v;
      A[u-1].push_back(v-1);
    }
  }


  vector<int> d(n, -1);
  vector<int> h(n, -1);

  int time = 0;
  for (int i=0; i<n; i++) {
    if (d[i] != -1) continue;

    time = dfs(i, time, A, d, h);
  }

  for (int i = 0; i < n; i++) {
    cout << i + 1 << " ";
    cout << d[i] << " ";
    cout << h[i] << endl;
  }
  return 0;
}
