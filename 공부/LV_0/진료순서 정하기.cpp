#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer(emergency.size(),0);
    for(int i=1; i<= emergency.size(); ++i) {
        auto p=max_element(emergency.begin(), emergency.end());
        answer[distance(emergency.begin(), p)] = i;
        *p = 0;
    }
    return answer;
}

int main()
{
    for (int n : solution({ 3,76,24 }))
    {
        cout << n << " ";
    }
}