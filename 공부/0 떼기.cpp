#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string n_str) {
    string answer = "";
    auto p=n_str.find_first_not_of('0');
    if (p != string::npos) answer = string( n_str.begin()+p, n_str.end() );
    return answer;
}

int main()
{
    cout << solution("0010");
}