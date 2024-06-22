#include <iostream>
using namespace std;

/* NOTE: 書籍の見本のプログラムだが個人的にわかりづらいと思う。 */
/*       自分で実装した ./b.cpp の方がわかりやすいと思う */

#define MAX 100005
#define NIL -1

/* データ構造 */
/*   Node のデータ構造には p に親を l に一番左の子を r に右隣の兄弟を格納する。 */
struct Node { int p, l, r };

Node T[MAX];
int n, D[MAX];

/* 深さ */
/*  ルートから順に辿って深さを計算することで各ノードへの訪問が 1 度で済み O(n) の計算量となる */
/*  深さは右隣のノードと一番左の子ノードを再帰的に計算する。 */
int depth(int u, int p) {
  D[u] = p;
  if (T[u].r != NIL) depth(T[u].r, p);
  if (T[u].l != NIL) depth(T[u].l, p+1);
};

int main() {
  n = 9;
  int nodes[9][3] = {
    {0, 1, NIL},
    {0, 2, 3},
    {1, NIL, NIL},
    {1, 4, 5},
    {3, NIL, NIL},
    {3, 6, NIL},
    {5, 7, NIL},
    {6, NIL, 8},
    {6, NIL, NIL}
  };

  for(int i = 0; i < n; i++) {
    T[i].p = nodes[i][0];
    T[i].l = nodes[i][1];
    T[i].r = nodes[i][2];
  }

  int root = 0;
  for(int i = 0; i < n; i++) {
    if(T[i].p == NIL) root = i;
  }

  depth(root, 0);

  for(int i = 0; i < n; i++) {
    cout << "node " << i << ": ";
    cout << "parent = " << T[i].p << ", ";
    cout << "depth = " << D[i] << ", ";

    if(T[i].p == NIL) cout << "root, ";
    else if(T[i].l == NIL) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";
    for(int j = 0, c = T[i].l; c != NIL; j++, c = T[c].r) {
      if(j) cout << ", ";
      cout << c;
    }
    cout << "]" << endl;
  }

  return 0;
}
