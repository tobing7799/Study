#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end(), less<>());
    
    for (int i = 0; i < A.size(); ++i) {
        answer += (A[i] * B[i]);
    }
    return answer;
}

int main()
{
    cout << solution({ 1,4,2 }, { 5,4,4 });
}