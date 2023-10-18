#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<int> result;

    sort(routes.begin(), routes.end(), [](vector<int>& a, vector<int>& b) {return a[0] < b[0]; });

    for (vector<int>v : routes) {
        if (result.size() && result.back() < v[0]) {
            result.clear();
            answer++;
        }
        if(result.empty()) result.push_back(v[1]);
        else if(result.back() > v[1]) result.push_back(v[1]);
    }

    if (result.size()) answer++;

    return answer;
}

int main()
{
    cout << solution({{-20, -15}, { -14, -5}, { -18, -13}, { -5, -3 }});
}