#include <stdio.h>
#include <math.h>

int binary_to_decimal(long long n)
{
	int dec = 0;
	int rem;	// ³ª¸ÓÁö

	for (int i = 0; i < 32; i++) {
		rem = n % 10;
		dec += rem * pow(2, i);
		n /= 10;
	}
	return dec;
}

int main()
{
	long long bin;
	int dec;

	printf("Enter binary number: ");
	scanf_s("%lld", &bin);

	dec = binary_to_decimal(bin);
	printf("%lld(binary) = %d(decimal)\n", bin, dec);
}