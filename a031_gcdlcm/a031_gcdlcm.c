#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int x, int y);

int main()
{
    int a, b, GCD, LCM;

    printf("2개의 정수를 입력하세요 :");
    scanf("%d %d", &a, &b);

    GCD = gcd(a, b);
    LCM = (a * b) / GCD;

    printf("GCD(%d, %d) = %d\n", a, b, GCD);
    printf("LCM(%d, %d) = %d\n", a, b, LCM);
}

int gcd(int x, int y)
{
    if (y == 0) {
        return x;
    }
    else {
        return gcd(y, x % y);
    }
}