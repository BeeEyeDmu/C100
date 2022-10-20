#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000
#define CNT 1000

int search(int a[], int v);
void printArr(int a[], int n);
void find_min_max(int a[], int n);

int main()
{
	int a[CNT];
	int value, index;

	srand(time(0));	// ���� �õ� ����
	for (int i = 0; i < CNT; i++)
		a[i] = rand() % MAX;

	printArr(a, CNT);
	find_min_max(a, CNT);
	printf("\nã���� �ϴ� ���� �Է��ϼ��� : ");
	scanf("%d", &value);

	if ((index = search(a, value)) == -1)
		printf("%d��(��) �迭 �ȿ� �����ϴ�.", value);
	else
		printf("%d��(��) a[%d]�� �ֽ��ϴ�.", value, index);
}

int search(int a[], int v)
{
	for (int i = 0; i < CNT; i++)
		if (a[i] == v)
			return i;
	return -1;
}

void find_min_max(int a[], int n)
{
	int min = a[0];
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	printf("\nmin = %d, max = %d", min, max);
}

void printArr(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%c%6d", (i % 10 == 0) ? '\n' : ' ', a[i]);
}