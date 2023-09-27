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

/*
int solution(string word) {
    string v = string("AEIOU");
    int a = word.size();

    for(int i = 0, b = 1; i < word.size(); i++, b *= 5)
        a += v.rfind(word[i]) * 781 / b;

    return a;
}
숫자를 이용해서 푸는 방법
이건 숫자의 규칙성을 알아야한다.
*/