#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& A, int g) {
  for (int i = g; i < A.size(); i++) {
    int v = A[i];
    int j = i - g;

    while (j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j -= g;
    }

    A[j + g] = v;
  }
}

vector<int> shellSort(const vector<int>& A) {
  vector<int> arr = A;
  int n = arr.size();

  vector<int> G;
  int h = 1;
  while (h <= n) {
    G.push_back(h);
    h = 3 * h + 1;
  }

  for (int i = G.size() - 1; i >= 0; i--) {
    insertionSort(arr, G[i]);
  }

  return arr;
}
