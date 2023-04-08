#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    vector<vector<int>>temp;
    double result1 = 0;
    double result2 = 0;
    for (int i = 1; i < dots.size(); ++i)
    {
        temp = dots;
        int dx = temp[i][0] - temp[i-1][0];
        int dy = temp[i][1] - temp[i-1][1];
        result1 = dy / (double)dx;
        temp.erase(temp.begin()+i);
        temp.erase(temp.begin()+i-1);
        dx = temp[1][0] - temp[0][0];
        dy = temp[1][1] - temp[0][1];
        result2 = dy / (double)dx;
        if (result1 == result2)
        {
            answer = 1;
            break;
        }
    }
    return answer;
}

int main()
{
    cout << solution({ {3,5},{4,1},{2,4},{5,10} });
}