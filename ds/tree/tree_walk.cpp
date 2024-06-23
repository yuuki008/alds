#include <iostream>
#include <vector>
using namespace std;

#define MAX 25
#define NIL -1

struct Node {
  int p, l, r;
  Node(): p(NIL), l(NIL), r(NIL) {}
};

vector<Node> nodes(MAX);

void preOrder(int id) {
  cout << " " << id;
  if (nodes[id].l != NIL) preOrder(nodes[id].l);
  if (nodes[id].r != NIL) preOrder(nodes[id].r);
}

void inOrder(int id) {
  if (nodes[id].l != NIL) inOrder(nodes[id].l);
  cout << " " << id;
  if (nodes[id].r != NIL) inOrder(nodes[id].r);
}

void postOrder(int id) {
  if (nodes[id].l != NIL) postOrder(nodes[id].l);
  if (nodes[id].r != NIL) postOrder(nodes[id].r);
  cout << " " << id;
}

int main () {
  int n;
  cin >> n;

  for(int i=0; i<n; i++) {
    int id, l, r;
    cin >> id >> l >> r;

    nodes[id].l = l;
    nodes[id].r = r;

    if (l != NIL) nodes[l].p = id;
    if (r != NIL) nodes[r].p = id;
  }

  int root = 0;
  for (int i=0;i<n;i++) {
    if(nodes[i].p == NIL) {
      root = i;
      break;
    }
  }

  cout << "Preorder" << endl;
  preOrder(root);
  cout << endl;

  cout << "Inorder" << endl;
  inOrder(root);
  cout << endl;

  cout << "Postorder" << endl;
  postOrder(root);
  cout << endl;
  return 0;
}
