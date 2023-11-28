#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    sort(strings.begin(), strings.end(), [&n](const string& a, const string& b) {
        if (a[n] == b[n]) return a < b;
        return a[n] < b[n]; });
    return answer = strings;
}

int main()
{
    for (string s : solution({"car","bed","sun"}, 1)) {
        cout << s << ' ';
    }
}