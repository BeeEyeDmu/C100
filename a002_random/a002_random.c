#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int a[10];
	int dice[30];
	int rand_min = 1;
	int rand_max = 6;

	srand(time(0));	// 현재 시간으로 랜덤 시드 설정
	for (int i = 0; i < 10; i++)
		a[i] = rand();

	for (int i = 0; i < 10; i++)
		printf("%6d ", a[i]);
	printf("\n");

	printf("   RAND_MAX = %x, %d\n", RAND_MAX, RAND_MAX);

	for (int i = 0; i < 30; i++) {
		dice[i] = (double)rand() / RAND_MAX
			* (rand_max - rand_min + 1) + rand_min;
		// dice[i] = rand() % rand_max + rand_min; // 이 방법도 가능
	}

	for (int i = 0; i < 30; i++)
		printf("%6d%c", dice[i], (i + 1) % 10 != 0 ? ' ' : '\n');
}