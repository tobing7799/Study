#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;

    vector<int> elements_2 = elements;
    elements_2.insert(elements_2.end(), elements.begin(), elements.end());
    unordered_set<int> part;

    for (int i = 0; i < elements.size(); ++i)
    {
        int sum = 0;
        for (int j = i; j < elements.size() + i; ++j) {
            sum += elements_2[j];
            part.insert(sum);
        }
    }
    return answer = part.size();
}

int main()
{
    cout << solution({ 7, 9, 1, 1, 4 });
}