#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> cards)
{
    int n = cards.size();
    vector<bool> vis(n + 1, false);
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        int cur = cards[i], cnt = 0;
        while (!vis[cur])
        {
            vis[cur] = true;
            cur = cards[cur - 1];
            cnt++;
        }
        if (cnt) result.push_back(cnt);
    }
    sort(result.begin(), result.end(), greater<int>());
    if (result.size() > 1) return result[0] * result[1];
    return 0;
}

int main()
{
    cout << solution({ 8,6,3,7,2,5,1,4 });
}