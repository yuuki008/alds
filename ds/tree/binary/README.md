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

# Treap

2 分探索木は挿入されるデータによって、偏った木になり、探索効率が悪くなる。
BST の構造のおいて木の高さが計算量に直結します。そして各葉の深さがどれだけ均一になっているかの度合いのことを平衡性と呼ぶ。
この木の平衡性を保つために Treap ではランダムな優先度を各ノードに付与して、木の平衡状態を保つ様に工夫しています。

## Treap の条件
- 二分探索木条件
    left が root の左の子なら left.key < root.key
    right が root の右の子なら root.key < right.key
- ヒープ条件
    child が parent の子なら child.priority < parent.priority

この Treap のデータ構造を保つために挿入時は以下の処理を行う。

1. 通常の BST 同様に insert 処理を行う
2. ヒープ条件を満たすまで **回転** を繰り返す

## 回転操作

親子関係を逆転させ、ヒープ条件と二分探索木条件の両方を満たす様に木を再構成する。

```
void rightRotate(Node p) {
  Node c = p.left;
  p.left = c.right;
  c.right = p;
  return c;
}

void leftRotate(Node p) {
  Node c = p.right;
  p.right = c.left;
  c.left = p;
  return c;
}
```

