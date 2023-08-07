#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer;
    int n = arr.size() - arr[0].size();
    if (n==0) answer = arr;
    else if (n>0)
    {
        for (auto& v : arr)
        {
            for (int i = 0; i < n; ++i)
            {
                v.push_back(0);
            }
        }
        answer = arr;
    }
    else
    {
        for (int i = 0; i < n*-1; ++i)
        {
            vector<int> temp(arr[0].size(), 0);
            arr.push_back(temp);
        }
        answer = arr;
    }
    return answer;
}

int main()
{
    for (auto v : solution({{ 572, 22, 37 }, { 287, 726, 384 }, { 85, 137, 292 }, { 487, 13, 876 }}))
    {
        for (int n : v)
        {
            cout << n << " ";
        }
        cout << endl;
    }
}