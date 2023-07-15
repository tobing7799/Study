#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<string> strArr) {
    int answer = 0;
    vector<int> num(31, 0);
    for (string s : strArr)
    {
        num[s.size()]++;
    }
    return answer = *max_element(num.begin(),num.end());
}

int main()
{
    cout << solution({ "a","bc","d","efg","hi" });
}