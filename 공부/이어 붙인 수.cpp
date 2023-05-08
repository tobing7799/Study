#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    string odd = "";
    string even = "";
    for (int n : num_list) {
        if (n % 2) odd += to_string(n);
        else even += to_string(n);
    }
    return answer = stoi(odd)+stoi(even);
}

int main()
{
    cout << solution({ 3,4,5,2,1 });
}