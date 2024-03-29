#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> type;
    for (int i = 0; i < survey.size(); ++i) {
        if (choices[i] != 4) choices[i] > 4 ? type[survey[i][1]] += (choices[i] - 4) : type[survey[i][0]] += (4 - choices[i]);
    }
    answer += type['R'] < type['T'] ? 'T' : 'R';
    answer += type['C'] < type['F'] ? 'F' : 'C';
    answer += type['J'] < type['M'] ? 'M' : 'J';
    answer += type['A'] < type['N'] ? 'N' : 'A';
    return answer;
}

int main()
{
    cout << solution({ "AN", "CF", "MJ", "RT", "NA" },{ 5, 3, 2, 7, 5 });
}