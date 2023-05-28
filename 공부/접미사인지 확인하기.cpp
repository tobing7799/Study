#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 0;
    for (int i = 0; i < my_string.size(); ++i) {
        if (is_suffix == my_string.substr(i))
        {
            answer = 1;
            break;
        }
    }
    return answer;
}

int main()
{
    cout << solution("banana", "ana");
}