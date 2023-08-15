#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int num) {
    string answer = "";
    return answer = num % 2 ? "Odd" : "Even";
}

int main()
{
    cout << solution(3);
}