#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for (int i = 0; i <= t.size()-p.size(); ++i)
    {
        int num = stoi(t.substr(i, p.size()));
        if (num <= stoi(p))
        {
            answer++;
        }
    }
    return answer;
}

int main()
{
    cout << solution("10203", "15");
}