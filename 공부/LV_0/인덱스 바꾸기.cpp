#include <string>
#include <vector>
#include<iostream>

using namespace std;

string solution(string my_string, int num1, int num2) {
    string answer = "";
    char temp;
    temp= my_string[num1];
    my_string[num1]= my_string[num2];
    my_string[num2] = temp;
    answer = my_string;
    return answer;
}

int main()
{
    cout << solution("hello", 1, 2);
}