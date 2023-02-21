#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string message) {
    return message.size() * 2;
}

int main()
{
    cout << solution("happy birthday!");
}