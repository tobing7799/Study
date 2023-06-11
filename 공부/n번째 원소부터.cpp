#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer(num_list.begin()+n-1, num_list.end());
    return answer;
}

int main()
{
    for (int n : solution({ 2,1,6 },3))
    {
        cout << n << " ";
    }
}