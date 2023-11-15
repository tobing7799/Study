#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int count = 0;
    for (string s : seoul) {
        if (s == "Kim") {
            answer = "�輭����";
            answer += to_string(count);
            answer += "�� �ִ�";
            break;
        }
        ++count;
    }

    return answer;
}

int main()
{
    cout << solution({ "Jane", "Kim" });
}