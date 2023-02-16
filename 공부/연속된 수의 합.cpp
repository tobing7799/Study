#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//������ �������� �� ���ڴ� �߾��� ����,
//������ �������� ������ ������ ¦�����̸� �߾ӿ��� ������ ����.

int* solution(int num, int total) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
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