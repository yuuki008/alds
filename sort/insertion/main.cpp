#include <vector>
#include <iostream>

using namespace std;

vector<int> insertionSort(const vector<int>& A) {
  vector<int> arr = A;
  int n = arr.size();

  for (int i = 1; i < n; ++i) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }

  return arr;
}
