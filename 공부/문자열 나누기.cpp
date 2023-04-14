#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string same;
    string other;
    for (int i = 0; i < s.size(); ++i) {
        if (same.empty()) same += s[i];
        else if (same[0] == s[i]) same += s[i];
        else other += s[i];

        if (same.size() == other.size())
        {
            string temp;
            temp = s.substr(i+1,s.size()-i-1);
            s = temp;
            same.clear();
            other.clear();
            i = -1;
            answer++;
        }
    }
    if (!same.empty()) answer++;
    return answer;
}

int main()
{
    cout << solution("abracadabra");
}