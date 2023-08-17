#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    transform(phone_number.cbegin(), phone_number.cend() - 4, phone_number.begin(), [](char c) { return '*'; });
    return answer = phone_number;
}

int main()
{
    cout << solution("01033334444");
}