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
	int* ptr;	// bsearch�� ���ϰ�(key ���� ����� ���� ������)
	int key;

	printf("ã���� �ϴ� ���� �Է��ϼ��� : ");
	scanf("%d", &key);

	ptr = (int*)bsearch(&key, a, 10, sizeof(int), compare);

	if (ptr != NULL)
		printf("%d��(��) a[%d]�� �ֽ��ϴ�.\n", *ptr, ptr - a);
	else
		printf("%d��(��) �迭 �ȿ� �����ϴ�.\n", key);
}