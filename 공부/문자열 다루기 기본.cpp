#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(string s) {
    bool answer = true;
    for (char c : s){
        if (isalpha(c)) return false;
    }
    if (s.size() != 4 && s.size() != 6) return false;
    return true;
}

int main()
{
    cout << boolalpha << solution("1234");
}