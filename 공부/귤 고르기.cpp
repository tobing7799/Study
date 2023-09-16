#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int>count;
    for (int n : tangerine) {
        count[n]++;
    }

    vector<pair<int, int>> vec(count.begin(), count.end());
    sort(vec.begin(),vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; });
    
    for (auto& pair: vec) {
        if (k <= 0) break;
        else {
            k -= pair.second;
            answer++;
        }
    }
    return answer;
}

int main()
{
    cout << solution(6,{ 1, 3, 2, 5, 4, 5, 2, 3 });
}