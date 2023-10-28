#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets)
{
    int answer = 0;
    int index = 0;
    sort(targets.begin(), targets.end());

    while (index < targets.size()) {
        int end = targets[index][1];
        index++;
        answer++;
        while (index < targets.size() && targets[index][0] < end) {
            if (targets[index][1] < end) end = targets[index][1];
            index++;
        }
    }
    return answer;
}

int main()
{
    cout << solution({ {4, 5},{4, 8},{10, 14},{11, 13},{5, 12},{3, 7},{1, 4} });
}