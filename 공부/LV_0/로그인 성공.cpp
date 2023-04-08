#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    for (vector<string> vector : db)
    {
        if (id_pw[0] == vector[0])
        {
            answer = "wrong pw";
            if (id_pw[1] == vector[1])
            {
                answer = "login";
            }
            break;
        }
        else
        {
            answer = "fail";
        }
    }
    return answer;
}

int main()
{
    cout << solution({ "meosseugi", "1234" }, { {"rardss", "123"} , {"yyoom", "1234"}, {"meosseugi", "1234"} });
}