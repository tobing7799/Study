#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    while (n % 2 == 0) {
        answer.push_back(2);
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            answer.push_back(i);
            n = n / i;
        }
    }

    if (n > 2) answer.push_back(n);

    answer.erase(unique(answer.begin(), answer.end()),answer.end());
    return answer;
}

int main()
{
    for (int n : solution(420)) {
        cout << n << " ";
    }
}
/*
아래 코드도 생각했지만 숫자가 큰 케이스에서 위 코드보다 더 느리게 작동했다.
그 이유를 예상하면 이 코드는 num을 더해가며 while을 순회하는데
위에 작성한 코드는 먼저 2로 나눠지는 값을 구한 후 제곱근을 이용하여 숫자를 검색하는 부분을 더 빠르게 진행하므로 반복문의 수행횟수가 적을 것이다.
vector<int> solution(int n) {
    vector<int> answer;
    int num = 2;
    while (n != 1)
    {
        if (n % num == 0) {
            n = n / num;
            answer.push_back(num);
        }
        else
            num++;
    }
    answer.erase(unique(answer.begin(), answer.end()),answer.end());
    return answer;
}
*/