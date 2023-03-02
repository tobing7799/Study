#include <string>
#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    vector<double>result;
    for (vector<int> n : score) {
        result.push_back(double((n[0] + n[1]) / 2.0));
    }
    for (int n : result)
    {
        answer.push_back(count_if(result.begin(), result.end(), [n](int a) {
            if (n < a) return true;
            else return false;
            })+1);
    }
    return answer;
}

int main()
{
    for (int n : solution({ { 1, 1 }, { 2, 2 }, {3, 3} ,{0, 0} }))
    {
        cout << n << endl;
    }
}