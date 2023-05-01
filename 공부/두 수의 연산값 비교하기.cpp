#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string str1 = to_string(a) + to_string(b);
    string str2 = to_string(2 * a * b);
    if (str1 == str2) return answer = stoi(str1);
    return answer = stoi(str1) > stoi(str2) ? stoi(str1) : stoi(str2);
}

int main()
{
    cout << solution(91,2);
}