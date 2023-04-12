#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    for (int i = 0; i < s.size(); ++i) {

        for (int j = i; j >= 0; --j)
        {
            if (s[j] == s[i] && i != j)
            {
                answer.push_back(i - j);
                break;
            }
            else if (j == 0)
            {
                answer.push_back(-1);
            }
        }
    }
    return answer;
}

int main()
{
    for (int i : solution("banana")) {
        cout << i << " ";
    }
}