#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    sort(skip.begin(), skip.end());
    for (char& c : s) {
        for (int i = 0; i < index; ++i)
        {
            if (c == 'z') c = 'a';
            else c++;
            if(skip.find(c) != string::npos) i -= 1;
        }
    }
    return answer = s;
}

int main()
{
    cout << solution("ybcde","az",1);
}