#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> list;
    for (int n : score)
    {
        if (list.size() < k) list.push_back(n);
        else
        {
            auto p = min_element(list.begin(), list.end());
            if (*p < n)
            {
                list.erase(p);
                list.push_back(n);
            }
        }
        auto p = min_element(list.begin(), list.end());
        answer.push_back(*p);
    }
    return answer;
}

int main()
{
    for (int n : solution(3, { 10,100,20,150,1,100,200 }))
    {
        cout << n << " ";
    }
}