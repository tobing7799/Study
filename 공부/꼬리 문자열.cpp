#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> str_list, string ex) {
    string answer = "";
    for (string s : str_list)
    {
        if (s.find(ex) == string::npos) answer += s;
    }
    return answer;
}

int main()
{
    cout << solution({ "abc", "def", "ghi" }, "ef");
}