#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
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