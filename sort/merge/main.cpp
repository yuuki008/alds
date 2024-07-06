#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void merge(vector<int>& A, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;

  vector<int> L(n1 + 1);
  vector<int> R(n2 + 1);

  for (int i = 0; i < n1; i++) L[i] = A[left + i];
  for (int i = 0; i < n2; i++) R[i] = A[mid + i];

  L[n1] = numeric_limits<int>::max();
  R[n2] = numeric_limits<int>::max();

  int l = 0;
  int r = 0;

  for (int i = left; i < right; i++) {
    if (L[l] <= R[r]) {
      A[i] = L[l];
      l++;
    } else {
      A[i] = R[r];
      r++;
    }
  }
}

void mergeSort(vector<int>& A, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
};
