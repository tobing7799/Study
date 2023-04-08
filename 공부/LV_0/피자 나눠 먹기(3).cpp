#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int slice, int n) {
    int answer = 0;
    return answer = n % slice ? (n / slice)+1 : (n / slice);
}

int main()
{
    cout << solution(4,12);
}