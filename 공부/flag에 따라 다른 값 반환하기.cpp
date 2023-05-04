#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, bool flag) {
    int answer = 0;
    return answer = flag ? a - (-b) : a-b;
}

int main()
{
    cout << solution(-4, 7, true);
}