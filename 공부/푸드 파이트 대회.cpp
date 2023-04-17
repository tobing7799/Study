#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> food) {
    string answer = "0";
    int middle = 0;
    for (int i = 1; i < food.size(); ++i)
    {
        int num = food[i] / 2;
        if (num)
        {
            for (int j = 0; j < num; ++j)
            {
                answer.insert(middle, (to_string(i)));
                middle += 1;
                answer.insert(middle + 1, to_string(i));
            }
            cout << answer << endl;
        }
    }
    return answer;
}

int main()
{
    cout << solution({1,3,4,6});
}