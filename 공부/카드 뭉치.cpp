#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "No";
    auto p1 = cards1.begin();
    auto p2 = cards2.begin();
    int count = 0;
    for (string s : goal) {
        if (*p1 == s)
        {
            count++;
            if(p1 != cards1.end()-1) p1++;
        }
        else if (*p2 == s)
        {
            count++;
            if (p2 != cards2.end() - 1) p2++;
        }
    }
    if (p1 == cards1.end() && p2 == cards2.end()) answer = "Yes";
    else if (count == goal.size()) answer = "Yes";
    return answer;
}

int main()
{
    //cout << solution({ "i","drink","water" }, { "want","to" }, { "i","want","to","drink","water" });
    //cout << solution({ "i","water","drink" }, { "want","to" }, { "i","want","to","drink","water" });
    cout << solution({ "a" }, { "b","d","c"}, {"a","b","c","d"});
}