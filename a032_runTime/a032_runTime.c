#include <stdio.h>
#include <time.h>

int main()
{
    double start, end;

    // 시작 시간
    start = (double)clock() / CLOCKS_PER_SEC;

    int sum = 0;
    for (int i = 0; i < 10000000; i++) {
        sum++;
    }

    // 끝 시간
    end = (double)clock() / CLOCKS_PER_SEC;
    printf("sum = %d, 실행 시간 = %lf초\n", sum, end - start);
}