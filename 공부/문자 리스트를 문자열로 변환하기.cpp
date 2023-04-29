#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> arr) {
    string answer = "";
    for (string c : arr)
    {
        answer += c;
    }
    return answer;
}

int main()
{
    cout << solution({"a", "b", "c"});
}