#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    for (int i = 0; i < strArr.size(); ++i)
    {
        if (i % 2) transform(strArr[i].begin(), strArr[i].end(), strArr[i].begin(), ::toupper);
        else transform(strArr[i].begin(), strArr[i].end(), strArr[i].begin(), ::tolower);
    }
    return answer = strArr;
}

int main()
{
    for (string s : solution({ "AAA","BBB","CCC","DDD" }))
    {
        cout << s << " ";
    }
}