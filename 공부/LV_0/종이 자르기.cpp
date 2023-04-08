#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int M, int N) {
    int answer = 0;
    
    for (int i = 0; i < M; ++i);
    {
        for (int j = N * M; j > 1; --j)
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    cout<< solution(1,1);
}