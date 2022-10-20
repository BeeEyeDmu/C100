#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int my_atoi(const char* s)
{
	int value = 0;

	while (*s) {
		if (*s >= '0' && *s <= '9') {
			value = value * 10 + *s - '0';
			s++;
		}
		else {
			printf("non-number found!");
			return -1;
		}
	}
	return value;
}

char* my_itoa(int v)
{
	int digits = 0;	// ÀÚ¸®¼ö
	int t = v;

	while (t) {
		digits++;
		t /= 10;
	}

	char* number = (char*)malloc(digits + 1);
	number[digits] = NULL;

	while (digits != 0) {
		number[--digits] = v % 10 + '0';
		v /= 10;
	}
	return number;
}

int main()
{
	char buffer[30];

	printf("atoi() : %d\n", atoi("1234567"));
	printf("my_atoi() : %d\n", my_atoi("1234567"));

	_itoa_s(1234567, buffer, _countof(buffer), 10);
	printf("_itoa_s() : %s\n", buffer);
	printf("my_itoa() : %s\n", my_itoa(1234567));
}