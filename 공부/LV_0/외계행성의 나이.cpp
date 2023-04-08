#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int age) {
    string answer = to_string(age);
    for (char& v : answer) {
        v += 'a' - '0';
    }
    return answer;
}

int main()
{
    cout << solution(51);
}

//¹æ¹ý 1
//string solution(int age) {
//    string answer = "";
//    while (age) {
//        answer.insert(0, string(1, char(age % 10 + 'a')));
//        age -= (age % 10);
//        age /= 10;
//    }
//    return answer;
//}