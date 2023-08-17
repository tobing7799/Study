#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    string num = to_string(n);
    int sum = 0;
    for (char c : num) {
        sum += c - '0';
    }
    answer = sum;
    cout << answer << endl;

    return answer;
}

int main()
{
    solution(123);
}