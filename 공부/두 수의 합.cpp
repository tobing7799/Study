#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string a, string b) {
    string answer = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        carry = sum / 10;
        answer = to_string(sum % 10) + answer;
    }
    return answer;
}

int main()
{
    cout << solution("18446744073709551615", "287346502836570928366");
}