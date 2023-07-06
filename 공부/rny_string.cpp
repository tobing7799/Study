#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string rny_string) {
    string answer = "";
    while (1)
    {
        if (rny_string.find("m") == string::npos) break;
        else
        {
            int p = rny_string.find("m");
            rny_string.insert(p + 1, "rn");
            rny_string.erase(p,1);
        }
    }
    return answer = rny_string;
}

int main()
{
    cout << solution("masterpiece");
}