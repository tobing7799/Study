#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num;

    for (int i = 0; i < numbers.size(); ++i) {
        num.push_back(to_string(numbers[i]));
    }
    sort(num.begin(), num.end(), [](const string& a, const string& b) { return a + b > b + a; });

    for (int i = 0; i < num.size(); ++i) {
        answer += num[i];
    }
    if (answer[0] == '0') answer = "0";
    return answer;
}

int main()
{
    cout << solution({ 151, 15, 1 });
}