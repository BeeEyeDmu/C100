#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000
#define CNT 1000

int binarySearch(int a[], int n, int v);
void swap(int v[], int i, int j);
void sort(int v[], int left, int right);
void printArr(int a[], int n);

int main()
{
	int a[CNT];
	int value, index;

	srand(time(0));	// 랜덤 시드 설정
	for (int i = 0; i < CNT; i++)
		a[i] = rand() % MAX;

	sort(a, 0, CNT);
	printArr(a, CNT);

	printf("\n찾고자 하는 값을 입력하세요 : ");
	scanf("%d", &value);

	if ((index = binarySearch(a, CNT, value)) == -1)
		printf("%d은(는) 배열 안에 없습니다.", value);
	else
		printf("%d은(는) a[%d]에 있습니다.", value, index);
}

void sort(int v[], int left, int right)
{
	for (int i = left; i < right; i++)
		for (int j = 0; j < right - 1; j++)
			if (v[j] > v[j + 1])
				swap(v, j, j + 1);
}

void swap(int v[], int i, int j)
{
	int tmp;

	tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

int binarySearch(int a[], int n, int v)
{
	int low = 0;
	int high = n - 1;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (a[mid] == v)
			return mid;
		else if (v > a[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

void printArr(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%c%6d", (i % 10 == 0) ? '\n' : ' ', a[i]);
}