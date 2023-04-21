#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int>pattern = { 1,2,3,1 };
    auto it = ingredient.begin();
    while (1)
    {
        it = search(it, ingredient.end(), pattern.begin(), pattern.end());
        if (it == ingredient.end()) break;
        else
        {
            int n = distance(ingredient.begin(), it)-2;
            ingredient.erase(it, it + 4);
            answer++;
            if (n > -1) it = ingredient.begin() + n;
            else it = ingredient.begin();
        }
    }
    return answer;
}

int main()
{
    cout << solution({ 1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1 });
}