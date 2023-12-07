#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    for (int i = 0; i < progresses.size(); ++i) {
        int temp = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i]) temp++;

        if (!q.empty() && q.front() > temp) {
            q.push(temp);
        }
        else if(!q.empty() && q.front() < temp){
            answer.push_back(q.size());
            q = queue<int>{};
            q.push(temp);
        }
        else {
            q.push(temp);
        }

    }
    if(!q.empty()) answer.push_back(q.size());
    return answer;
}

int main()
{
    for (int n : solution({ 93,30,55 }, { 1,30,5 })) {
        cout << n << ' ';
    }
}