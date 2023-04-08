#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string letter) {
    string answer = "";
    vector<string> v{ ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
    stringstream ss(letter);
    string s = "";
    while (getline(ss, s, ' ')){
         answer += distance(v.begin(),find(v.begin(), v.end(), s))+'a';
    }
    return answer;
}

int main()
{
    cout << solution(".... . .-.. .-.. ---");
}