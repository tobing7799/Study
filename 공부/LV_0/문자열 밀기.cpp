#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    string str_pre = "";
    string str_next = "";
    if (A == B)
    {
        return 0;
    }
    for (int i = 1; i < A.length(); ++i)
    {
        str_next = A.substr(0, A.length() - i);
        str_pre = A.substr(A.length() - i);
        if (B.find(str_next)<B.length() && B.find(str_pre)<B.length())
        {
            answer = i;
            return i;
        }
    }
    return -1;
}

int main()
{
    string a = "abc";
    string b = "abc";
   cout << solution(a,b);
}

/*
int solution(string A, string B) {
    B+=B;
    return B.find(A);
}
���� ��ģ Ǯ�̹�
�ݵ�� ��ȯ�ϰ� �Ǿ������� ���ڿ��� �ι����ؼ� �� �ȿ� �ִ����� Ȯ���ϸ� �Ǵ� ������ ����
*/