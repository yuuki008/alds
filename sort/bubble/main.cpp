#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> bubbleSort(const vector<int>& A) {
  vector<int> arr = A;
  int n = arr.size();

  bool swapped;

  do {
    swapped = false;
    for (int i = 1; i < n; ++i) {
      if (arr[i] < arr[i - 1]) {
        swap(arr[i], arr[i - 1]);
        swapped = true;
      }
    }
    --n; // 最後の要素はすでにソートされている
  } while (swapped);

  return arr;
}

