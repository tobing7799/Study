#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> str_list) {
    vector<string> answer;
    auto l = find(str_list.begin(), str_list.end(), "l");
    auto r = find(str_list.begin(), str_list.end(), "r");

    if (distance(str_list.begin(), l) < distance(str_list.begin(), r))
    {
        answer.assign(str_list.begin(), l);
    }
    else if (distance(str_list.begin(), l) > distance(str_list.begin(), r))
    {
        answer.assign(r+1 , str_list.end());
    }

    return answer;
}

int main()
{
    for (string s : solution({ "u", "r", "u", "u" }))
    {
        cout << s << " ";
    }
}