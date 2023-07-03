#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer(count(myString.begin(), myString.end(), 'x')+1);
    int n = 0;
    for (char c : myString)
    {
        if (c == 'x')
        {
            n++;
        }
        else answer[n] += c;
    }
    answer.erase(remove(answer.begin(), answer.end(),""), answer.end());
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    for (string s : solution("dxccxbbbxaaaa"))
    {
        cout << s << " ";
    }
}