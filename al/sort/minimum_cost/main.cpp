#include <cwchar>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

static const int MAX = 10;
static const int VMAX = 10;

int minimumCost(vector<int> A) {
    int n = A.size();
    int max_v = *std::max_element(A.begin(), A.end());

    vector<bool> V(n, false);
    vector<int> B(n);
    vector<int> T(max_v + 1);

    for(int i = 0; i < n; i++) {
        B[i] = A[i];
    }

    sort(B.begin(), B.end());

    for(int i = 0; i < n; i++) {
        T[B[i]] = i;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if (V[i]) continue;

        int cur = i;
        int S = 0;
        int m = INT_MAX;
        int an = 0;

        while (true) {
            V[cur] = true;
            an++;
            int v = A[cur];
            m = min(m, v);
            S += v;
            cur = T[v];
            if (V[cur]) break;
        }

        ans += min(S + (an - 2) * m, m + S + (an + 1) * B[0]);
    }

    return ans;
}

int main() {
    vector<int> A = {4, 3, 2, 7, 1, 6, 5};

    int ans = minimumCost(A);

    cout << ans << endl;

    return 0;
}

