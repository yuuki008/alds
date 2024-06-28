#include <iostream>
#include <vector>
using namespace std;

void maxifyHeap(vector<int> &A, int i, int heapSize) {
  int left = i * 2 + 1;
  int right = i * 2 + 2;
  int largest = i;

  if (left < heapSize && A[left] > A[largest])
    largest = left;
  if (right < heapSize && A[right] > A[largest])
    largest = right;

  if (largest != i) {
    swap(A[i], A[largest]);
    maxifyHeap(A, largest, heapSize);
  }
}

void buildMaxHeap(vector<int> &heap) {
  int heapSize = heap.size();

  /* 一番下の内部ノードからルートに向けて maxifyHeap を行う。 */
  /* 葉に対して maxifyHeap を行わないのはすでにヒープ条件を満たしているから。 */
  for (int i = heapSize / 2 - 1; i >= 0; i--) {
    maxifyHeap(heap, i, heapSize);
  }
}

int main() {
  int H;
  cin >> H;
  vector<int> heap(H);

  for (int i = 0; i < H; i++)
    cin >> heap[i];

  buildMaxHeap(heap);

  for (int i = 0; i < heap.size(); i++) {
    cout << " " << heap[i];
  }
  cout << endl;

  return 0;
}
