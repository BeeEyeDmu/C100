#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int x, y, n;
    int a[100][100] = { 0, };

    printf("input number(Ȧ��) : ");
    scanf("%d", &n);

    int col = n / 2;
    int row = 0;

    for (int i = 1; i <= n * n; i++) {
        a[row][col] = i;
        int t_row = row - 1; // �� ĭ ����
        int t_col = col + 1; // �� ĭ ������
        if (t_row == -1)   // ���� ���� �Ѿ�� ���� �Ʒ��� �̵�
            t_row = n - 1;
        if (t_col == n)    // �������� �Ѿ�� �������� �̵�
            t_col = 0;
        if (a[t_row][t_col] != 0)  // �̹� ä���� �ִٸ� �Ʒ�ĭ���� �̵�
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