#include <string>
#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    bitset<10>A{ bin1 };
    bitset<10>B{ bin2 };
    bitset<11>C{ A.to_ulong() + B.to_ulong() };
    answer = C.to_string();
    while (answer[0] == '0' && answer[1]!=NULL) {
        answer.erase(answer.begin());
    }
    return answer;
}

int main()
{
    cout << solution("10", "11");
}