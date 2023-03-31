#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    sort(array.begin(), array.end());
    return answer = array[array.size()/2];
}

int main()
{
    cout << solution({ 1,2,7,10,11 });
}