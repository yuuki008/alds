#include <iostream>
#include <vector>

using namespace std;

/* INPUT */
/* 4 */
/* 1 2 2 4 */
/* 2 1 4 */
/* 3 0 */
/* 4 1 3 */

/* GOAL */
/* 1 0 */
/* 2 1 */
/* 3 2 */
/* 4 1 */

void bfs(int key, vector<vector<int>>&A, vector<int>& d, int distance) {
  if (d[key] != -1 && distance > d[key]) return;

  d[key] = distance;

  for (int i=0; i<A[key].size(); i++) {
    bfs(A[key][i], A, d, distance+1);
  }
}

int main () {
  /* int n=3; */
  /* vector<vector<int>> A = { */
  /*   { 1 }, */
  /*   { 2 }, */
  /*   { 0 }, */
  /* }; */

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

  bfs(0, A, d, 0);

  for(int i=0; i<n; i++) {
    cout << i+1 << " " << d[i] << endl;
  }
  return 0;
}
