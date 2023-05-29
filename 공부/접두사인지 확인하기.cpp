#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string my_string, string is_prefix) {
    int answer = 0;
    return answer = my_string.substr(0,is_prefix.size()) == is_prefix;
}

int main()
{
    cout << solution("banana", "ban");
}