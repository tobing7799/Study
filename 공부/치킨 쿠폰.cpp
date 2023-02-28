#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    int last = 0;
    while (chicken / 10 >= 1 ) {
        last = chicken%10;
        chicken /= 10;
        answer += chicken;
        chicken += last;
    }
    return answer;
}

int main()
{
    cout << solution(1081);
}