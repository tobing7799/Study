#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;
    switch (n) {
    case 1:
        answer.assign(num_list.begin(), num_list.begin() + slicer[1] + 1);
        break;
    case 2:
        answer.assign(num_list.begin() + slicer[0], num_list.end());
        break;
    case 3:
        answer.assign(num_list.begin() + slicer[0], num_list.begin() + slicer[1] + 1);
        break;
    case 4:
        for (int i = slicer[0]; i <= slicer[1]; i += slicer[2]) {
            answer.push_back(num_list[i]);
        }
        break;
    }
    return answer;
}

int main()
{
    for (int n : solution(3, { 1, 5, 2 },{ 1, 2, 3, 4, 5, 6, 7, 8, 9 }))
    {
        cout << n << " ";
    }
}