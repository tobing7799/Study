#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    string num = to_string(n);
    string temp;
    for (char c : num) {
        temp = c;
        answer += stoi(temp);
    }
    return answer;
}

int main()
{
    cout << solution(1234);
}

/*
numeric�̶�� ����� iterator�� �Ѱ��ָ� �ش� �����̳ʿ� ����ִ� ���� ���� �����ִ� �Լ��� �ִ�.
*/