#include <iostream>
#include <vector>
using namespace std;

const int MAX = 25;
const int NIL = -1;

struct Node {
  int p, l, r;
  Node() : p(NIL), l(NIL), r(NIL) {}
};

vector<Node> nodes(MAX);
vector<int> depths(MAX);
vector<int> sibling(MAX, NIL);
vector<int> degrees(MAX, 0);
vector<int> heights(MAX);
int max_depth = 0;

/**
 * Computes the depth and height of the nodes in a binary tree.
 *
 * @param id The ID of the current node.
 * @param depth The depth of the current node.
 * @return The height of the current node.
 */
int computeDepthAndHeight(int id, int depth) {
  if (depth > max_depth) max_depth = depth;
  depths[id] = depth;

  int l = nodes[id].l;
  int r = nodes[id].r;

  int leftHeight = 0;
  int rightHeight = 0;
  if (l != NIL) leftHeight = computeDepthAndHeight(l, depth + 1);
  if (r != NIL) rightHeight = computeDepthAndHeight(r, depth + 1);

  int height = (leftHeight > rightHeight) ? leftHeight : rightHeight;
  heights[id] = height;
  return height + 1;
}

int main() {
  int n = 9;

  vector<vector<int>> lines = {
    {0, 1, 4},
    {1, 2, 3},
    {2, NIL, NIL},
    {3, NIL, NIL},
    {4, 5, 8},
    {5, 6, 7},
    {6, NIL, NIL},
    {7, NIL, NIL},
    {8, NIL, NIL}
  };

  for (const vector<int>& line : lines) {
    int id = line[0];
    int l = line[1];
    int r = line[2];

    nodes[id].l = l;
    nodes[id].r = r;

    if (l != NIL) {
      nodes[l].p = id;
      degrees[id]++;
    }

    if (r != NIL) {
      nodes[r].p = id;
      degrees[id]++;
    }

    if (l != NIL && r != NIL) {
      sibling[l] = r;
      sibling[r] = l;
    }
  }

  // Find the root
  int root = 0;
  for (int i = 0; i < n; i++) {
    if (nodes[i].p == NIL) {
      root = i;
      break;
    }
  }

  computeDepthAndHeight(root, 0);

  for (int i = 0; i < n; i++) {
    cout << "node " << i << ": ";
    cout << "parent = " << nodes[i].p << ", ";
    cout << "sibling = " << sibling[i] << ", ";
    cout << "degree = " << degrees[i] << ", ";
    cout << "depth = " << depths[i] << ", ";
    cout << "height = " << heights[i] << ", ";

    if (nodes[i].p == NIL) cout << "root";
    else if (nodes[i].l == NIL && nodes[i].r == NIL) cout << "leaf";
    else cout << "internal node";
    cout << endl;
  }

  return 0;
}

