#include <stdio.h>

char* to_upper(char* s)
{
	char* ptr = s;
	while (*ptr) {
		if (*ptr >= 'a' && *ptr <= 'z')
			*ptr = *ptr - 'a' + 'A';
		ptr++;
	}
	return s;
}

char* to_lower(char* s)
{
	char* ptr = s;
	while (*ptr) {
		if (*ptr >= 'A' && *ptr <= 'Z')
			*ptr = *ptr - 'A' + 'a';
		ptr++;
	}
	return s;
}

int main()
{
	char s[] = "Hello World!";

	printf("to_upper() : %s\n", to_upper(s));
	printf("to_lower() : %s\n", to_lower(s));
}