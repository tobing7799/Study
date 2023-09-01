#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n) {
    int answer = 0;
    string num;
    while (n != 0) {
        num += to_string(n % 3);
        n /= 3;
    }
    
    for (int i = num.size()-1; i>=0; --i)
    {
        answer += pow(3, num.size() - 1 - i) * (num[i] - '0');
    }
    return answer;
}

int main()
{
    cout << solution(45);
}