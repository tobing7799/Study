#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int solution(string n_str) {
    int answer = 0;
    stringstream ss(n_str);
    ss >> answer;
    return answer;
}

int main()
{
    cout << solution("10");
}