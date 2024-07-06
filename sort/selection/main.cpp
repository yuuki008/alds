#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> selectionSort(const vector<int>& A) {
  vector<int> arr = A;
  int n = arr.size();

  for (int i = 0; i < n; ++i) {
    int min_i = i;
    for (int j = i + 1; j < n; ++j) {
      if (arr[j] < arr[min_i]) {
        min_i = j;
      }
    }
    swap(arr[i], arr[min_i]);
  }

  return arr;
};
