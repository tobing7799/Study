#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string my_string, int s, int e) {
    string answer = "";
    reverse(my_string.begin() + s, my_string.begin() + e+1);
    return answer = my_string;
}

int main()
{
    cout << solution("Progra21Sremm3", 6, 12);
}