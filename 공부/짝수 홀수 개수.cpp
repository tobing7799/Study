#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    int even_count = 0;
    even_count=count_if(num_list.begin(), num_list.end(), [](int x) { return x % 2 == 0; });
    int odd_count = num_list.size() - even_count;
    answer.push_back(even_count);
    answer.push_back(odd_count);
    return answer;
}

int main()
{
    for (int n : solution({ 1,2,3,4,5 })) {
        cout << n << " ";
    }
}