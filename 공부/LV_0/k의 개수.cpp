#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    string s;
    for (i; i <= j; ++i)
    {
        s += to_string(i);
    }
    answer = count(s.begin(), s.end(), k + 48);
    return answer;
}

int main()
{
    cout << solution(10,50,5);
}

//#include <numeric> //�ڵ尡 ���ڰ� Ŀ���� Ŀ������ �� �������� ������ �� ������ �ذ��ϴ� �� �ٸ� ���.
//int solution(int i, int j, int k) {
//    int answer = 0;
//    vector<int> temp(j - i + 1);
//    char num = k + 48;
//    iota(temp.begin(), temp.end(), i);
//    for (int c : temp) {
//        string s = to_string(c);
//        answer += count(s.begin(), s.end(), num);
//    }
//    return answer;
//}