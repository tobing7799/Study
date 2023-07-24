#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string a, string b) {
	//int carry = 0;
	//int len = a.size() > b.size() ? a.size() : b.size();
 //   string answer= "";
	//int(a[0]-'0') + int(b[0]-'0') > 9 ? answer.resize(len + 1) : answer.resize(len);
	//reverse(a.begin(), a.end());
	//reverse(b.begin(), b.end());
	//for (int i = 0; i < len; i++) {
	//	int sum = a[i] - '0' + b[i] - '0' + carry;
	//	while (sum < 0) sum += '0';
	//	if (sum > 9) carry = 1;
	//	else carry = 0;
	//	answer[i] = sum % 10 + '0';
	//}
	//if (carry == 1) answer[len] = '1';
	//reverse(answer.begin(), answer.end());
 //   return answer;

    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    string answer = "";

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
        answer = std::to_string(sum % 10) + answer;
    }

    return answer;
}

int main()
{
    cout << solution("18446744073709551615", "287346502836570928366");
}