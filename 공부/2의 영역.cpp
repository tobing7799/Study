#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if (find(arr.begin(), arr.end(), 2) == arr.end()) return { -1 };

    int start = -1, end = -1;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 2)
        {
            start = i;
            break;
        }
    }
    for (int i = arr.size() - 1; i >= 0; --i) {
        if (arr[i] == 2)
        {
            end = i;
            break;
        }
    }
    answer.assign(arr.begin() + start, arr.begin() + end + 1);
    return answer;
}
int main()
{
    for (int n : solution({ 1, 2, 1, 4, 5, 2, 9 })) {
        cout << n << " ";
    }
}