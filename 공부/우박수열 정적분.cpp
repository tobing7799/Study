#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges)
{
    vector<double> answer;
    vector<pair<int, int>> result;
    result.push_back({ 0,k });

    for (int i = 1; k != 1; ++i) {
        if (k % 2) k = 3 * k + 1;
        else k /= 2;
        result.push_back({ i, k });
    }
    for (vector<int> v : ranges) {
        int start = v[0], end = result.size() - 1 + v[1];
        double num = 0;
        for (int i = start; i < end; i++) {
            num += (double)(result[i].second + result[i + 1].second) / 2;
        }
        if (start > end) answer.push_back(-1.0);
        else answer.push_back(num);
    }
    return answer;
}

int main()
{
    for (double d : solution(5, { {0,0},{0,-1},{2,-3},{3,-3} })) {
        cout << d << " ";
    }
}