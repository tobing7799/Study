#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    for (int i = l; i <= r; ++i)
    {
        string s = to_string(i);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '5' && s[i] != '0')
            {
                break;
            }
            if (i == s.size() - 1) answer.push_back(stoi(s));
        }
    }
    if (answer.empty()) answer.push_back(-1);
    return answer;
}

int main()
{
    for (int n : solution(5, 555)) {
        cout << n << " ";
    }
}