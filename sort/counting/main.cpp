#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> countingSort(const vector<int>& A) {
  int n = A.size();
  int min_val = INT_MAX;
  int max_val = INT_MIN;

  for (int i = 0; i < n; i++) {
    if (A[i] < min_val) min_val = A[i];
    if (A[i] > max_val) max_val = A[i];
  }

  int range = max_val - min_val + 1;

  vector<int> count(range, 0);
  vector<int> sorted_array(n);

  for (int i = 0; i < n; i++) count[A[i] - min_val]++;
  for (int i = 1; i < range; i++) count[i] += count[i - 1];

  for (int i = n - 1; i >= 0; i--) {
    int sorted_index = count[A[i] - min_val] - 1;
    sorted_array[sorted_index] = A[i];
    count[A[i] - min_val]--;
  }

  return sorted_array;
}
;
