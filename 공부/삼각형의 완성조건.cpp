#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    sort(sides.begin(), sides.end());
    if (*sides.begin() + *(sides.begin() + 1) > *sides.rbegin()) answer = 1;
    else answer = 2;
    return answer;
}

int main()
{
    cout << solution({ 199, 72, 222 });
}