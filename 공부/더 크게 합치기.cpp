#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string sa = to_string(a);
    string sb = to_string(b);
    string sc = to_string(a) + to_string(b);
    if (a == b) return answer = stoi(sc);
    return answer = stoi(sa + sb) > stoi(sb + sa) ? stoi(sa + sb) : stoi(sb + sa);
}

int main()
{
    cout << solution(9, 91);
}