#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int t) {
    int answer = 0;
    if (--t == 0) return n*=2;
    answer = solution(n*2, t);
    return answer;
}

int main()
{
    cout << solution(2,10);
}

/*
int solution(int n, int t) {
    return n << t;
}
쉬프트 연산하면 되는데..
*/