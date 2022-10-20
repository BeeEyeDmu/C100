#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int x, y, n;
    int a[100][100] = { 0, };

    printf("input number(홀수) : ");
    scanf("%d", &n);

    int col = n / 2;
    int row = 0;

    for (int i = 1; i <= n * n; i++) {
        a[row][col] = i;
        int t_row = row - 1; // 한 칸 위쪽
        int t_col = col + 1; // 한 칸 오른쪽
        if (t_row == -1)   // 제일 위를 넘어서면 제일 아래로 이동
            t_row = n - 1;
        if (t_col == n)    // 오른쪽을 넘어서면 왼쪽으로 이동
            t_col = 0;
        if (a[t_row][t_col] != 0)  // 이미 채워져 있다면 아래칸으로 이동
            row++;
        else {
            row = t_row;
            col = t_col;
        }
    }

    int sum_col;
    for (int i = 0; i < n; i++) {
        sum_col = 0;
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
            sum_col += a[i][j];
        }
        printf(" ->%4d", sum_col);
        printf("\n");
    }
}