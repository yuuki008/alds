#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int> &A, int i, int heapSize) {
  int left = i * 2 + 1;
  int right = i * 2 + 2;
  int largest = i;

  if (left < heapSize && A[left] > A[largest])
    largest = left;
  if (right < heapSize && A[right] > A[largest])
    largest = right;

  if (largest != i) {
    swap(A[largest], A[i]);
    maxHeapify(A, largest, heapSize);
  }
}

void buildMaxHeap(vector<int> &A) {
  int n = A.size();
  for (int i = n / 2 - 1; i >= 0; i--) {
    maxHeapify(A, i, n);
  }
}

void heapSort(vector<int> &A) {
  buildMaxHeap(A);

  int n = A.size();
  for (int i = n - 1; i > 0; i--) {
    swap(A[0], A[i]);
    maxHeapify(A, 0, i);
  }
}

int main() {
  vector<int> A = {3, 5, 1, 10, 2, 7};
  heapSort(A);

  for (int i = 0; i < A.size(); i++) {
    cout << A[i] << " ";
  }
  cout << endl;
  return 0;
}
