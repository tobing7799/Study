#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int price) {
    int answer = 0;
    return answer = (price >= 500000) ? price * 0.8 :
        (price >= 300000) ? price * 0.9 :
        (price >= 100000) ? price * 0.95 : price;
}

int main()
{
    cout << solution(150000);
}