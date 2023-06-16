#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> names) {
    vector<string> answer;
    for (int i = 0; i < names.size(); ++i)
    {
        if (!(i % 5)) answer.push_back(names[i]);
    }
    return answer;
}

int main()
{
    for (string s : solution({ "nami", "ahri", "jayce", "garen", "ivern", "vex", "jinx" }))
    {
        cout << s << " ";
    }
}