#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    sort(d.begin(), d.end());
    for (int n : d) {
        budget -= n;
        if (budget >= 0) answer++;
        else break;
    }
    return answer;
}

int main()
{
    cout << solution({1,3,2,5,4}, 9);
}