#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(vector<int> A) {
  for(auto a : A) cout << a << " ";
  cout << endl;
};

vector<int> buildPostOrder(vector<int> preOrder, vector<int> inOrder) {
  if (inOrder.size() == 0 || preOrder.size() == 0) return vector<int>{};

  int root = preOrder[0];
  auto it = find(inOrder.begin(), inOrder.end(), root);
  int index = distance(inOrder.begin(), it);

  vector<int> leftPreOrder(preOrder.begin() + 1, preOrder.begin() + 1 + index);
  vector<int> leftInOrder(inOrder.begin(), inOrder.begin() + index);

  vector<int> rightPreOrder(preOrder.begin() + 1 + index, preOrder.end());
  vector<int> rightInOrder(inOrder.begin() + index + 1, inOrder.end());

  vector<int> leftPostOrder = buildPostOrder(leftPreOrder, leftInOrder);
  vector<int> rightPostOrder = buildPostOrder(rightPreOrder, rightInOrder);

  vector<int> postOrder;
  postOrder.insert(postOrder.end(), leftPostOrder.begin(), leftPostOrder.end());
  postOrder.insert(postOrder.end(), rightPostOrder.begin(), rightPostOrder.end());
  postOrder.push_back(root);

  return postOrder;
}

int main () {
  int n=5;
  vector<int> preOrder = { 1, 2, 3, 4, 5 };
  vector<int> inOrder = { 3, 2, 4, 1, 5 };

  vector<int> postOrder = buildPostOrder(preOrder, inOrder);

  printArray(postOrder);
  return 0;
}
