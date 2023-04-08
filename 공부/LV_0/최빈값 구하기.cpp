#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    vector<int> num(1000);
    for (int n : array) {
        num[n]++;
    }
    auto p = max_element(num.begin(), num.end());
    int count = 0;
    for (int n : num) {
        if (*p == n ) count++;
    }

    if (count == 1) answer = distance(num.begin(), p);
    else answer = -1;
    return answer;
}

int main()
{
    cout << solution({ 1,2,3,3,3,4 });
}