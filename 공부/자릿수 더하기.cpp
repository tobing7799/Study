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
numeric이라는 헤더에 iterator를 넘겨주면 해당 컨테이너에 들어있는 값의 합을 구해주는 함수가 있다.
*/