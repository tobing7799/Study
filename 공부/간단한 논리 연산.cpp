#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(bool x1, bool x2, bool x3, bool x4) {
    bool answer = true;
    return answer = (x1 || x2) && (x3 || x4);
}

int main()
{
    cout << solution(0, 1, 1, 1);
}