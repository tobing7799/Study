#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    for (string s : picture)
    {
        string temp;
        for (char c : s)
        {
            for (int i = 0; i < k; ++i) temp += c;
        }
        for (int i = 0; i < k; ++i) answer.push_back(temp);
    }
    return answer;
}

int main()
{
    for (string s : solution({ ".xx...xx.", "x..x.x..x", "x...x...x", ".x.....x.", "..x...x..", "...x.x...", "....x...." }, 2))
    {
        cout << s << endl;
    }
}