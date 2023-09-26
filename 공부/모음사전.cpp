#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

void Make(set<string>&set, int len, string s, string vowel) {
    if (len == s.size()) {
        set.insert(s);
        return;
    }

    for (int i = 0; i < 5; ++i) {
        Make(set, len, s + vowel[i], vowel);
    }
}

int solution(string word) {
    int answer = 0;
    string vowel = "AEIOU";
    set<string>set;

    for (int i = 0; i < 5; ++i) {
        Make(set, i + 1, "", vowel);
    }
    
    return answer = distance(set.begin(), set.find(word)) + 1;
}

int main()
{
    cout << solution("I");
}