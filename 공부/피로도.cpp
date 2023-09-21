#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;

    vector<vector<int>> dp(dungeons.size() + 1, vector<int>(k + 1, 0));

    sort(dungeons.begin(), dungeons.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] - a[1] < b[0] - b[1]; });

    for (int i = 1; i <= dungeons.size(); ++i) {
        for (int j = 1; j <= k; j++) {

            if (dungeons[i - 1][0] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else dp[i][j] = max(dp[i - 1][j], 1 + dp[i - 1][j - dungeons[i - 1][1]]);
        }
    }

    return dp[dungeons.size()][k];
}

int main()
{
    cout << solution(80, { {80,20}, {50,40}, {30,10} });
}