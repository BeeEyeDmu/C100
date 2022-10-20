#include <stdio.h>
#include <string.h>

char* my_reverse(char* s)
{
	char* end = s + strlen(s) - 1;

	for (char* ptr = s; ptr < end; ptr++, end--) {
		char tmp = *ptr;
		*ptr = *end;
		*end = tmp;
	}
	return s;
}

int main()
{
	char s[] = "Hello World!~";

	printf("_strrev() : %s\n", _strrev(s));
	printf("my_reverse() : %s\n", my_reverse(s));
}