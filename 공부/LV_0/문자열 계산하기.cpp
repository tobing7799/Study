#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string my_string) {
    int answer = 0;

    my_string.erase(remove(my_string.begin(), my_string.end(), ' '), my_string.end());
    string temp;
    for (char c : my_string) {
        if (c == '+' || c == '-')
        {
            answer += stoi(temp);
            temp.clear();
        }
        temp += c;
    }
    return answer + stoi(temp);
}

int main()
{
    string a{"1 - 20 + 30 - 4"};
    cout << solution(a);
}