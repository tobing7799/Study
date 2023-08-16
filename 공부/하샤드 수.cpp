#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {
    bool answer = true;
    string str = to_string(x);
    int sum = 0;
    for (char c : str) {
        sum += c - '0';
    }

    return answer = x % sum ? false : true;
}

int main()
{
    cout<<solution(11);
}