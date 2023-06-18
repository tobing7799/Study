#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> todo_list, vector<bool> finished) {
    vector<string> answer;
    for (string s : todo_list)
    {
        if (!finished.front()) answer.push_back(s);
        finished.erase(finished.begin());
    }
    return answer;
}

int main()
{
    for (string s : solution({ "problemsolving", "practiceguitar", "swim", "studygraph" }, { true, false, true, false }))
    {
        cout << s << " ";
    }
}