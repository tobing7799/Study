#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer;
    for (auto p = num_list.begin(); p != num_list.end(); p++)
    {
        if(distance(num_list.begin(),p)%n==0) answer.push_back(*p);
    }
    return answer;
}

int main()
{
    for (int n : solution({ 4,2,6,1,7,6 }, 4))
    {
        cout << n << " ";
    }
}