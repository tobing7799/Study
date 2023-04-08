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
�Ʒ� �ڵ嵵 ���������� ���ڰ� ū ���̽����� �� �ڵ庸�� �� ������ �۵��ߴ�.
�� ������ �����ϸ� �� �ڵ�� num�� ���ذ��� while�� ��ȸ�ϴµ�
���� �ۼ��� �ڵ�� ���� 2�� �������� ���� ���� �� �������� �̿��Ͽ� ���ڸ� �˻��ϴ� �κ��� �� ������ �����ϹǷ� �ݺ����� ����Ƚ���� ���� ���̴�.
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