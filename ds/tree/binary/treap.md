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

親子関係を逆転させ、ヒープ条件と二分探索木条件の両方満たす様に木を再構成する。

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

