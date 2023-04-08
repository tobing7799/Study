#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//나누어 떨어지면 그 숫자는 중앙의 숫자,
//나누어 떨어지지 않으면 정답은 짝수개이며 중앙에서 왼쪽의 숫자.

int* solution(int num, int total) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer= (int*)malloc(sizeof(int*)*num);
    int max = INT_MIN;
    int divide = total/num;
    int result = 0;
    int count = 0;

    for (int j = num; j >=0; --j)
    {
        for (int i = 0; i < num; ++i)
        {
            result += divide - j + i;
            max = divide - j + i;
            count++;
        }
        if (result == total && count == num)
        {
            for (int i = 0; i < num; ++i)
            {
                *(answer + i) = max - num + i + 1;
            }
            break;
        }
        else
        {
            max = INT_MIN;
            result = 0;
            count = 0;
        }
    }
    return answer;
}


int main()
{
    int num = 1;
    int total = -5;

    auto p = solution(num, total);

    for (int i = 0; i < num; ++i)
    {
        printf("%d\n", *(p + i) );
    }
}