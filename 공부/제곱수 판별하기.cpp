#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 2;

    for (int i = 1; i*i <= n; ++i)
    {
        if (i*i == n)
        {
            answer = 1;
            break;
        }
    }
    return answer;
}

int main()
{
    cout << solution(144);
}

/*
int solution(int n) {

    int i = sqrt(n);

    if (pow(i, 2) == n)
        return 1;
    else
        return 2;
}
//�������� ���� ���
�������� ���ϸ� �Ǵ°ǵ�...
*/