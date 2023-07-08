#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
    for (char& c : myStr) {
        if (c < 'd') c = ' ';
    }
    stringstream ss(myStr);
    string s;
    while (ss >> s){
        answer.push_back(s);
    }
    if(answer.empty()) answer.push_back("EMPTY");
    return answer;
}

int main()
{
    for (string s : solution("baconlettucetomato"))
    {
        cout << s << " ";
    }
}