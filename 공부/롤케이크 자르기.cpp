#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> count;
    unordered_map<int, int> deleted;

    for (int n : topping) {
        count[n]++;
    }

    for (int n : topping) {
        deleted[n]++;
        count[n]--;
        if (!count[n])count.erase(n);
        if (count.size() == deleted.size()) answer++;
    }

    return answer;
}

int main()
{
    cout << solution({ 1, 2, 1, 3, 1, 4, 1, 2 });
}
// 1 2 1 3 1 4 1 2

// 1 2 2 3 3 4 4 4
// 