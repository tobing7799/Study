#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) {
    string answer = "";
    int partsNum = 0;
    for (string s : my_strings) {
        answer+=s.substr(parts[partsNum][0], parts[partsNum][1]- parts[partsNum][0] +1);
        partsNum++;
    }
    return answer;
}

int main()
{
    cout << solution({ "progressive", "hamburger", "hammer", "ahocorasick" }, { {0,4},{1,2},{3,5}, {7,7} });
}