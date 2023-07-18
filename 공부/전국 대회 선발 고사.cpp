#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    vector<int>num;
    int answer = 0;
    int p = 1;
    int d = 0;
    while (num.size()<3)
    {
        d=distance(rank.begin(),find(rank.begin(), rank.end(), p));
        if (attendance[d])
        {
            num.push_back(d);
        }
        p++;
    }
    return answer = num[0] * 10000 + num[1] * 100 + num[2];
}

int main()
{
    cout << solution({ 3, 7, 2, 5, 4, 6, 1 },{ false, true, true, true, true, false, false });
}