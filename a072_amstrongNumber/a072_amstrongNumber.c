#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int checkAmstrong(int origin)
{
    int n = origin;
    int digits = 0;
    int sum = 0;

    while (n != 0) {    // 자리수 찾기
        n /= 10;
        digits++;
    }
    n = origin;
    while (n != 0) {
        int rem = n % 10;
        sum += pow(rem, digits);
        n /= 10;
    }
    if (origin == sum)
        return 1;
    else
        return 0;
}

int main()
{
    int from, to;

    printf("암스트롱 수를 찾는 범위를 입력하세요(from to): ");
    scanf("%d %d", &from, &to);

    for (int i = from; i <= to; i++) {
        if (checkAmstrong(i) == 1)
            printf("%8d", i);
    }
}

