# BST ( Binary Search Tree )

## Delete

BST で削除するノードには 3 種類ある。
- 葉（子を持たないノード）
- 1 つの子ノードを持つノード
- 2 つの子ノードを持つノード

### 2 つの子ノードを持つノード

削除対象をルートに BST を削除する方法として以下 2 つの方法がある。
- 左部分木から一番大きな値をルートにする
- 右部分木から一番小さな値をルートにする

```c
Node *deleteNode(Node *root, int v) {
  if (root == nullptr)
    return root;

  /* 削除するノードの探索 */
  if (v < root->val) {
    root->left = deleteNode(root->left, v);
    return root;
  }

  if (v > root->val) {
    root->right = deleteNode(root->right, v);
    return root;
  }

  /* 削除対象ノードが leaf もしくは子ノードが 1 つだった場合 */
  if (!root->left) {
    Node *tmp = root->right;
    delete root;
    return tmp;
  } else if (!root->right) {
    Node *tmp = root->left;
    delete root;
    return tmp;
  };

  /* 削除対象ノードの子ノードが 2
   * つだった場合を右部分木で一番小さい値をルートにセットする */
  Node *tmp = root->right;
  while (tmp && tmp->left)
    tmp = tmp->left;
  root->val = tmp->val;
  root->right = deleteNode(root->right, tmp->val);
  return root;
};
```


