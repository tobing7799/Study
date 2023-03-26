#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    reverse(num_list.begin(), num_list.end());
    return answer=num_list;
}

int main()
{
    for (int n : solution({ 1,2,3,4,5 })) {
        cout << n << " ";
    }
}