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
내가 놓친 풀이법
반드시 순환하게 되어있으니 문자열을 두번더해서 그 안에 있는지만 확인하면 되는 간단한 문제
*/