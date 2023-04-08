#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    vector<int> temp;
    auto p = num_list.begin();
    for (int i = 1; p != num_list.end(); ++i)
    {
        temp.push_back(*p);
        ++p;
        if (i % n==0)
        {
            answer.push_back(temp);
            temp.clear();
        }
    }
    return answer;
}

int main()
{
    for (vector<int> v : solution({ 1,2,3,4,5,6,7,8 }, 2)) {
        for (int n : v) {
            cout << n << " ";
        }
        cout << endl;
    }
}