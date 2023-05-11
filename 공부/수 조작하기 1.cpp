#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, string control) {
    int answer = 0;
    for (char c : control) {
        if (c == 'w') n += 1;
        else if (c == 's') n -= 1;
        else if (c == 'd') n += 10;
        else  n -= 10;
    }
    return answer = n;
}

int main()
{
    cout << solution(0, { "wsdawsdassw" });
}