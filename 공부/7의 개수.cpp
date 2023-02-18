#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;

    for (int elem : array) {
        string num = to_string(elem);
        answer += count(num.begin(), num.end(), '7' );
    }
    
    return answer;
}

int main()
{
    vector<int>array{7,77,17};

    cout << solution(array);
}