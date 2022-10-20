#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000
#define CNT 100

void printArr(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%c%6d", (i % 10 == 0) ? '\n' : ' ', a[i]);
}

int compare(const void* p, const void* q)
{
	return *(int*)p - *(int*)q;
}

int bSearch(int a[], int low, int high, int key)
{
	if (low <= high) {
		int mid = (low + high) / 2;
		if (key == a[mid])
			return mid;
		else if (key > a[mid])
			return bSearch(a, mid + 1, high, key);
		else
			return bSearch(a, low, mid - 1, key);
	}
	return -1;
}

int main()
{
	int a[CNT];
	int value, index;

	srand(time(0));	// 랜덤 시드 설정
	for (int i = 0; i < CNT; i++)
		a[i] = rand() % MAX;

	qsort(a, CNT, sizeof(int), compare);
	printArr(a, CNT);

	printf("\n찾고자 하는 값을 입력하세요 : ");
	scanf("%d", &value);

	if ((index = bSearch(a, 0, CNT - 1, value)) == -1)
		printf("%d은(는) 배열 안에 없습니다.", value);
	else
		printf("%d은(는) a[%d]에 있습니다.", value, index);
}