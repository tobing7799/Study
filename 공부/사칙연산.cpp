#include <vector>
#include <string>
#include <iostream>
#include <limits.h>

using namespace std;

int solution(vector<string> arr) {
    int n = arr.size() / 2 + 1;
    vector<vector<int>> dpMax(n, vector<int>(n, INT_MIN));
    vector<vector<int>> dpMin(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; ++i) {
        dpMax[i][i] = stoll(arr[i * 2]);
        dpMin[i][i] = stoll(arr[i * 2]);
    }

    for (int len = 1; len < n; ++len) {
        for (int i = 0; i < n - len; ++i) {
            int j = i + len;
            for (int k = i; k < j; ++k) {
                if (arr[k * 2 + 1] == "+") {
                    dpMax[i][j] = max(dpMax[i][j], dpMax[i][k] + dpMax[k + 1][j]);
                    dpMin[i][j] = min(dpMin[i][j], dpMin[i][k] + dpMin[k + 1][j]);
                }
                else {
                    dpMax[i][j] = max(dpMax[i][j], dpMax[i][k] - dpMin[k + 1][j]);
                    dpMin[i][j] = min(dpMin[i][j], dpMin[i][k] - dpMax[k + 1][j]);
                }
            }
        }
    }

    return dpMax[0][n - 1];
}

int main()
{
    cout << solution({ "1", "-", "3", "+", "5", "-", "8" });
}