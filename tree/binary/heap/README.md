# Heap

木構造の 1 つで二分木で表現される。
木構造はポイントや配列を使って実装されるが、確保するメモリ領域と計算速度の観点から見て配列による実装のようが良いとされている。

各ノードへのアクセスは以下の様に行う。

- root i=1
- parent i/2
- left 2i
- right 2i+i

## 参考記事
https://medium.com/@yasufumy/data-structure-heap-ecfd0989e5be
