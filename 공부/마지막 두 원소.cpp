#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    int back = num_list[num_list.size() - 1];
    int front = num_list[num_list.size() - 2];
    if (front < back) num_list.push_back(back - front);
    if (front >= back) num_list.push_back(back * 2);
    return answer = num_list;
}

int main()
{
    for (int n : solution({ 2,1,6 })) {
        cout << n << " ";
    }
}