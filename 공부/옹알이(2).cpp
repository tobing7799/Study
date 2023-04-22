#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string>list = {"aya","ye","woo","ma"};
    for (string s : babbling) {
        int p = 0;
        for (string s1 : list) {
            while (1) {
                auto it = search(s.begin(), s.end(), s1.begin(), s1.end());
                if (it == s.end()) break;
                s.erase(it, it + s1.size());
                s.insert(it, '1'+p);
            }
            p++;
        }
		for (int i = 0; i < s.size(); ++i)
		{
			if (isalpha(s[i])) break;
			if (i > 0 && s[i] == s[i - 1]) break;
			else if (i == s.size() - 1) answer++;
		}
    }
    return answer;
}

int main()
{
    cout << solution({ "aya", "yee", "u" });
}