#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for (int i = 0; i <= t.size()-p.size(); ++i)
    {
        long long  num = stol(t.substr(i, p.size()));
        if (num <= stol(p))
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