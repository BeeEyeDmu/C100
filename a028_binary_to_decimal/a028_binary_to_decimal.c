#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

long long decimal_to_binary(int dec)
{
	long long bin = 0;
	int mask = 0x01;
	int bit;

	for (int i = 0; i < 16; i++) {
		bit = dec & mask;
		bin += bit * pow(10, i);
		dec = dec >> 1;
	}
	return bin;
}

int main()
{
	long long bin;
	int dec;

	printf("Enter decimal number: ");
	scanf("%d", &dec);

	bin = decimal_to_binary(dec);
	printf("%d(decimal) = %lld(binary)\n", dec, bin);
}