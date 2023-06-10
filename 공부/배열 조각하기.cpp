#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer = arr;

   for (int i = 0; i < query.size(); i++) {
       if (i % 2 == 0) answer.erase(answer.begin() + query[i] + 1, answer.end());
       else answer.erase(answer.begin(), answer.begin() + query[i]);
   }
    return answer;
}

int main()
{
    for (int n : solution({ 0, 1, 2, 3, 4, 5 }, { 4, 1, 2 }))
    {
        cout << n << " ";
    }
}