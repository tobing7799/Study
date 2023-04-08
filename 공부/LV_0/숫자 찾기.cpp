#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(int num, int k) {
    int answer = 0;
    string temp = to_string(num);
    answer = temp.find(to_string(k));
    if (answer == std::string::npos) return -1;
    return answer+1;
}

int main()
{
    cout << solution(29183, 7);
}