#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

void printResult(int a[], int n, double t) {
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n����ð� = %lf\n", t);
}

// n�ױ����� �Ǻ���ġ ������ ���ϴ� ����Լ�
int RecurFibonacci(int n) {
    if (n == 1 || n == 2)
        return 1;
    else
        return RecurFibonacci(n - 1) + RecurFibonacci(n - 2);
}

// n�ױ����� �Ǻ���ġ ������ ���ϴ� ���� ���α׷�
int dp[100];

int DynaFibonacci(int n) {
    if (n == 1 || n == 2)
        return 1;
    if (dp[n] != 0)  // �̹� ����� �Ǿ��ٸ�
        return dp[n];
    else
        return dp[n] = DynaFibonacci(n - 1) + DynaFibonacci(n - 2);
}

int main()
{
    double start, end;
    int n;
    int f[100];

    printf("n �ױ����� �Ǻ���ġ������ ����մϴ�.\nn�� �Է��ϼ��� : ");
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