#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRIALS 1000000   // 주사위 던지는 횟수

int main()
{
	int cnt[13] = { 0 };	// 2~12까지의 두 주사위 합을 저장하는 배열 
	int rand_min = 1;     // 한 주사위의 최소값
	int rand_max = 6;     // 한 주사위의 최대값
	int dice;	           // 주사위의 합

	srand(time(0));	   // 랜덤 시드 설정

	int v = rand_max - rand_min + 1;
	for (int i = 0; i < TRIALS; i++) {
		dice = (int)(rand() / ((double)RAND_MAX + 1) * v + rand_min);
		dice += (int)(rand() / ((double)RAND_MAX + 1) * v + rand_min);
		cnt[dice]++;
	}

	int total = 0;
	for (int i = 2; i <= 12; i++) {
		printf("cnt[%2d] = %8d, %5.2f%%\n", i, cnt[i], (double)cnt[i] / TRIALS * 100);
		total += cnt[i];
	}
	printf("TRIALS =  %d\n", total);
}