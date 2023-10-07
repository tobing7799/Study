#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    answer[1] = sequence.size();
    int index = 0;
    int sum = 0;
    for (int i = 0; i < sequence.size(); ++i) {
        sum += sequence[i];
        while (sum > k) {
            sum -= sequence[index];
            index++;
        }
        if (sum == k && ((i - index) < (answer[1] - answer[0]))) {
            answer[0] = index;
            answer[1] = i;
        }
    }
    return answer;
}

int main()
{
    for (int n : solution({ 1, 2, 3, 4, 5 }, 7)) {
        cout << n << " ";
    }
}