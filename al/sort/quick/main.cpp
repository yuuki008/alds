#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& A, int l, int r) {
  int pivot = A[r];
  int i = l - 1;

  for (int j = l; j < r; j++) {
    if (A[j] < pivot) {
      i++;
      swap(A[j], A[i]);
    }
  }

  swap(A[i + 1], A[r]);
  return i + 1;
}

void quickSort(vector<int>& A, int l, int r) {
  if (l < r) {
    int mid = partition(A, l, r);
    quickSort(A, l, mid - 1);
    quickSort(A, mid + 1, r);
  }
}

