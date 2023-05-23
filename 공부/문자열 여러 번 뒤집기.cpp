#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = "";
    for (auto v : queries) {
        while(v[0]<v[1])
        {
            swap(my_string[v[0]], my_string[v[1]]);
            v[0]++;
            v[1]--;
        }
    }
    return answer = my_string;
}

int main()
{
    cout << solution("rermgorpsam", { {2,3},{0,7},{5,9},{6,10} });
}