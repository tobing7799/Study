#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end(), greater<>());
    for (auto it = score.begin(); it != score.end(); it += m)
    {
        if (distance(it, score.end()) < m) break;
        answer += (*(it+m-1) * m);
    }
    return answer;
}

int main()
{
    cout << solution(4, 3, { 4,1,2,2,4,4,4,4,1,2,4,2 });
}