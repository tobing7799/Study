#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer;
    for (string s : strlist)
    {
        answer.push_back(s.size());
    }
    return answer;
}

int main()
{
    for (int n : solution({ "We", "are", "the", "world!" }))
    {
        cout << n << " ";
    }
}