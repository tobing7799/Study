#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    vector <int> temp(201,0);
    for (auto p : lines)
    {
        for (int i = p[0]; i < p[1]; ++i)
        {
            temp[i + 100]++;
        }
    }
    for (int i : temp)
    {
        if (i > 1) answer++;
    }
    return answer;
}

int main()
{
    cout << solution({ {0,1},{2,5},{3,9}});
}