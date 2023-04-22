#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> a(10);
    vector<int> b(10);

    for (int i = 0; i < X.size() || i < Y.size(); ++i)
    {
        if (i < X.size()) a[X[i] - '0']++;
        if (i < Y.size()) b[Y[i] - '0']++;
    }

    for (int i = 9; i >= 0; --i)
    {
        while (a[i] && b[i]) {
            answer += '0' + i;
            a[i]--;
            b[i]--;
        }
    }
    if (answer.empty()) answer = "-1";
    else if (answer[0] == '0') answer = '0';
    return answer;
}

int main()
{
    cout << solution("100", "203045");
}