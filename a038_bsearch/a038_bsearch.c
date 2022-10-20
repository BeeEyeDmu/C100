#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int a[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	int* ptr;	// bsearch의 리턴값(key 값이 저장된 곳의 포인터)
	int key;

	printf("찾고자 하는 값을 입력하세요 : ");
	scanf("%d", &key);

	ptr = (int*)bsearch(&key, a, 10, sizeof(int), compare);

	if (ptr != NULL)
		printf("%d은(는) a[%d]에 있습니다.\n", *ptr, ptr - a);
	else
		printf("%d은(는) 배열 안에 없습니다.\n", key);
}