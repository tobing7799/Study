#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int count = 0;
    int removed = 0;

    while (s != "1") {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                removed++;
            }
        }
        s.erase(remove(s.begin(), s.end(), '0'), s.end());

        int length = s.length();
        s = "";
        while (length > 0) {
            s = to_string(length % 2) + s;
            length /= 2;
        }

        count++;
    }
    answer.push_back(count);
    answer.push_back(removed);
    return answer;
}

int main()
{
    for (int n : solution("110010101001")) {
        cout << n << " ";
    }
}