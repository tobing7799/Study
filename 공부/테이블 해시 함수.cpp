#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end)
{
    int answer = 0;
    int index = col - 1;
    sort(data.begin(), data.end(), [&index](vector<int> a, vector<int> b){
        if (a[index] == b[index]) return a[0] > b[0];
        return a[index] < b[index]; });

    vector<int> s_i;

    for (int i = row_begin - 1; i <= row_end - 1; ++i)
    {
        int num = 0;
        for (int j = 0; j < data[i].size(); ++j) {
            num += data[i][j] % (i + 1);
        }
        s_i.push_back(num);
    }

    answer = s_i[0];

    for (int i = 1; i < s_i.size(); ++i) {
        answer = answer ^ s_i[i];
    }

    return answer;
}

int main()
{
    cout << solution({ {2,2,6},{1,5,10},{4,2,9},{3,8,3} }, 2, 2, 3);
}