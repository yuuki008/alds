#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Node {
  public:
    int id;
    int parent;
    int depth;
    vector<int> children;

    Node(int id) : id(id), parent(-1), depth(0) {}

    string type() const {
      if (parent == -1) return "root";
      else if (children.empty()) return "leaf";
      return "internal node";
    }
};

void setDepth(int id, vector<Node>& nodes, int depth) {
  nodes[id].depth = depth;
  for (int childId : nodes[id].children) {
    setDepth(childId, nodes, depth + 1);
  }
}

int main() {
  int n;
  cin >> n;

  vector<Node> nodes(n);
  for (int i = 0; i < n; ++i) {
    int id, k;
    cin >> id >> k;
    nodes[id] = Node(id);
    for (int j = 0; j < k; ++j) {
      int c;
      cin >> c;
      nodes[id].children.push_back(c);
    }
  }


  // parent の設定
  for (auto& node : nodes) {
    for (int childId : node.children) {
      nodes[childId].parent = node.id;
    }
  }

  // root を見つける
  int rootId = 0;
  for (const auto& node : nodes) {
    if (node.parent == -1) {
      rootId = node.id;
      break;
    }
  }

  // 深さをセット
  setDepth(rootId, nodes, 0);


  // 出力
  for (const auto& node : nodes) {
    cout << "node " << node.id << ": ";
    cout << "parent = " << node.parent << ", ";
    cout << "depth = " << node.depth << ", ";
    cout << node.type() << ", ";

    cout << "[";
    for (size_t j = 0; j < node.children.size(); ++j) {
      cout << node.children[j];
      if (j < node.children.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
  }

  return 0;
}

