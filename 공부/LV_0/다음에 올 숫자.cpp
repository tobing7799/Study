#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;

    auto a= *common.begin();
    auto b = *(common.begin() + 1);
    auto c = *(common.begin() + 2);

    auto end = *common.rbegin();

    int sub = b - a;

    if (sub + b == c)
    {
        return end + sub;
    }
    
    int division = b/a;

    if (division * b == c)
    {
        return end * division;
    }
    return 0;
}

int main()
{
    vector<int> a{2, 4, 8};

    cout << solution(a);
}