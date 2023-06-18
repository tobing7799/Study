#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> numbers, int n) {
    int answer = 0;
    for (int num : numbers)
    {
        answer += num;
        if (answer > n) break;
    }
    return answer;
}

int main()
{
    cout << solution({ 34, 5, 71, 29, 100, 34 }, 123);
}