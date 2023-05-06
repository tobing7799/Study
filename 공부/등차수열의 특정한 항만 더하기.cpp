#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int answer = 0;
    for (bool v : included)
    {
        if (v) answer += a;
        a += d;
    }
    return answer;
}

int main()
{
    cout << solution(3, 4, { 1,0,0,1,1 });
}