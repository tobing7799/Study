#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n,0));

    int num = 1;
    int rowStart = 0, rowEnd = n - 1;
    int colStart = 0, colEnd = n - 1;

    while (num <= n * n) {
        for (int i = colStart; i <= colEnd; ++i) {
            answer[rowStart][i] = num++;
        }
        ++rowStart;

        for (int i = rowStart; i <= rowEnd; ++i) {
            answer[i][colEnd] = num++;
        }
        --colEnd;

        for (int i = colEnd; i >= colStart; --i) {
            answer[rowEnd][i] = num++;
        }
        --rowEnd;

        for (int i = rowEnd; i >= rowStart; --i) {
            answer[i][colStart] = num++;
        }
        ++colStart;
    }
    return answer;
}

int main()
{
    for (auto v : solution(4))
    {
        for (int n : v)
        {
            cout << n << " ";
        }
        cout << endl;
    }
}