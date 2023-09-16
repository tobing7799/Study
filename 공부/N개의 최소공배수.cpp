#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int Lcm(int a, int b) {
    return (a * b) / Gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        answer = Lcm(answer, arr[i]);
    }

    return answer;
}

int main()
{
    cout << solution({ 2,6,8,14 });
}