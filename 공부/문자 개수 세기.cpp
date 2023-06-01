#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52);
    for (char c : my_string) {
        if (isupper(c)) answer[c - 'A']++;
        else answer[toupper(c) - 'A' + 26]++;
    }
    return answer;
}

int main()
{
    for (int n : solution("Programmers")) {
        cout << n << " ";
    }
}