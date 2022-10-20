#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

void printResult(int a[], int n, double t) {
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n실행시간 = %lf\n", t);
}

// n항까지의 피보나치 수열을 구하는 재귀함수
int RecurFibonacci(int n) {
    if (n == 1 || n == 2)
        return 1;
    else
        return RecurFibonacci(n - 1) + RecurFibonacci(n - 2);
}

// n항까지의 피보나치 수열을 구하는 동적 프로그램
int dp[100];

int DynaFibonacci(int n) {
    if (n == 1 || n == 2)
        return 1;
    if (dp[n] != 0)  // 이미 계산이 되었다면
        return dp[n];
    else
        return dp[n] = DynaFibonacci(n - 1) + DynaFibonacci(n - 2);
}

int main()
{
    double start, end;
    int n;
    int f[100];

    printf("n 항까지의 피보나치수열을 계산합니다.\nn을 입력하세요 : ");
    scanf("%d", &n);

    start = clock() / CLOCKS_PER_SEC;
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    end = clock() / CLOCKS_PER_SEC;
    printResult(f, n, end - start);

    start = clock() / CLOCKS_PER_SEC;
    for (int i = 1; i <= n; i++)
        f[i] = RecurFibonacci(i);
    end = clock() / CLOCKS_PER_SEC;
    printResult(f, n, end - start);

    start = clock() / CLOCKS_PER_SEC;
    for (int i = 1; i <= n; i++)
        f[i] = DynaFibonacci(i);
    end = clock() / CLOCKS_PER_SEC;
    printResult(f, n, end - start);
}