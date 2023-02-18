#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;

    for (int i = 0; i < my_str.length(); i += 6)
    {
        answer.push_back(my_str.substr(i, 6));
    }
    return answer;
}

int main()
{
    string input = "abc1Addfggg4556b";
    auto output = solution(input, 6);

    for(string a: output){
        cout << a << endl;
    }
}