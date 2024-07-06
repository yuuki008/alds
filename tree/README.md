# 根付き木 [Root Tree]
木構造の一種で、特定の「根」と言われるノードが存在する。
この「根」を起点として、他の全てノードが人方向に配置される階層構造。

## 基本構造
- 根 Root
- 節 Node
- 葉 Leaf
- 内部節 Internal Node
- 親 Parent
- 兄弟 Sibling
- 深さ Depth
- 高さ Height
    特定のノードから最も遠いはまでのエッジの数
- 次数 Degree
    ノードが持つ子の数

# 二分木
各ノードが最大で 2 つの子ノードを持つツリー構造。

## 基本操作
- 挿入 Intersion
- 削除 Deletion
- 探索 Search
- 巡回 Traversal
    - 前順巡回
    - 中順巡回
    - 後順巡回

## 効果的なるアルゴリズム

### 二分探索木 (Binary Search Tree)

ノードの左部分木にはノードの値より小さい値、右部分木には大きい値が格納される。
これによりノードへの大小で範囲を 1/2 に絞り込みながら探索を行える。
探索の平均が O(log n) となる

### バランスドツリー (Balanced Trees)

挿入や削除後にバランスを保つことで最悪の場合でも O(log n) の操作時間を保証するバイナリーツリー。

- ヒープ
- セグメントツリー
- トライ



# 関連問題
- [RootTree](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_A)
- [BinaryTree](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_B)
- [TreeWalk](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_C)
- [ReconstructionOfATree](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_D)
- [BinarySearchTree1](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_8_A)
- [BinarySearchTree2](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_8_B)
- [BinarySearchTree3](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_8_C)
