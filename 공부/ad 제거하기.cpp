#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    strArr.erase(remove_if(strArr.begin(), strArr.end(), [](string s) { if (s.find("ad") != string::npos) return true; else return false; }), strArr.end());
    return answer = strArr;
}

int main()
{
    for (string s : solution({ "and","notad","abcd" }))
    {
        cout << s << " ";
    }
}