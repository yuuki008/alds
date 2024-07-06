#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

// [参考問題]
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_D
// [チャット]
// https://chatgpt.com/c/f78937e3-a34e-415c-b685-ef9c87a9089a
// [解説]
// 最小コストは、コストを持つ配列をソートするときの最小となるコストを計算するアルゴリズムです。
// アルゴリズムのアプローチはこちらです。
//  1.配列の中でサイクルを見つける
//  2.サイクルごとの計算をする
//    サイクルの中の交換コストは、以下どちらか少ない値を採用する
//    A.サイクル内の最小値
//      サイクル合計重量 + (長さ - 2) * サイクル内最小重量
//    B.サイクル外の最小値
//      サイクル最小重量 + サイクル合計重量 + (サイクル長さ+1) * 配列最小重量

int minimumCost(vector<int> weights) {
    int numItems = weights.size();
    int maxW = *std::max_element(weights.begin(), weights.end());

    vector<bool> visited(numItems, false);     // [false, false, false, false, false, false, false]
    vector<int> finalPosition(maxW + 1);       // [0, 0, 0, 0, 0, 0, 0, 0]
    vector<int> sorteds=weights;
    sort(sorteds.begin(), sorteds.end());      // [1, 2, 3, 4, 5, 6, 7]

    // ソート後の各要素の位置を格納
    for(int i = 0; i < numItems; i++) {        // [0, 0, 1, 2, 3, 4, 5, 6]
        finalPosition[sorteds[i]] = i;
    }

    // 各サイクルの合計を SUM する
    int total = 0;
    for(int i = 0; i < numItems; i++) {
        if (visited[i]) continue;

        int currentIndex = i;
        int sum = 0;
        int minW = INT_MAX;
        int length = 0;

        while (true) {
            visited[currentIndex] = true;           // 現在の荷物を訪問済みに
            length++;                               // サイクルの数を格納
            int current = weights[currentIndex];    // 現在の荷物の重さを取得
            minW = min(minW, current);              // サイクルの最小の荷物を更新
            sum += current;                         // 合計に現在の荷物を加算
            currentIndex = finalPosition[current];  // 現在の荷物のソート後の位置を取得
            if (visited[currentIndex]) break;       // 次の荷物が訪問済みであれば break
        }


        // サイクル内の最小コスト 合計重量 + (長さ - 2) * 最小重量
        // サイクル外の最小コスト
        total += min(sum + (length - 2) * minW,
                         minW + sum + (length + 1) * sorteds[0]);
    }

    return total;
}

int main() {
    vector<int> weights = {4, 3, 2, 7, 1, 6, 5};

    int minimumSortingCost = minimumCost(weights);

    cout << minimumSortingCost << endl;

    return 0;
}
