#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string, vector<int> index_list) {
    string answer = "";
    for (int n : index_list)
    {
        answer += my_string[n];
    }
    return answer;
}

int main()
{
    cout << solution("cvsgiorszzzmrpaqpe",{ 16, 6, 5, 3, 12, 14, 11, 11, 17, 12, 7 });
}