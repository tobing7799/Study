#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string myString) {
    string answer = "";
    transform(myString.begin(), myString.end(), myString.begin(), ::toupper);
    return answer = myString;
}

int main()
{
    cout << solution("aBcDeFg");
}