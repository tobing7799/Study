#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int mul = 1;
    int add_pow = 0;
    for (int n : num_list)
    {
        mul *= n;
        add_pow += n;
    }
    add_pow *= add_pow;
    return answer = mul > add_pow;
}

int main()
{
    cout << solution({ 3,4,5,2,1 });
}