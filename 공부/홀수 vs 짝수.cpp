#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int odd = 0;
    int even = 0;
    for (int i = 1; i <= num_list.size(); ++i)
    {
        if (i % 2) odd += num_list[i-1];
        else even += num_list[i-1];
    }
    return answer = odd > even ? odd  : even;
}

int main()
{
    cout << solution({ 4,2,6,1,7,6 });
}