#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> cards)
{
    int answer = 0;
    vector<bool> totalcard(cards.size() + 1, false);
    vector<int> result;
    for (int i = 0; i < cards.size(); ++i) {
        int index = cards[i];
        int cnt = 0;
        while (!totalcard[index]) {
            totalcard[index] = true;
            index = cards[index - 1];
            cnt++;
        }
        if (cnt) result.push_back(cnt);
    }
    sort(result.begin(), result.end(), greater<int>());
    if (result.size() > 1) answer = result[0] * result[1];
    return answer;
}

int main()
{
    cout << solution({ 8,6,3,7,2,5,1,4 });
}