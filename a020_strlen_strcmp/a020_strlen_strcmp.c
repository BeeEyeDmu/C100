#include <stdio.h>
#include <string.h>

size_t my_strlen(const char* s)
{
	size_t i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}

size_t my_strlen2(const char* s)
{
	char* p = s;
	while (*p != '\0')
		p++;
	return p - s;
}

// s < t이면 -1, s == t 이면 0, s > t 이면 +1
int my_strcmp(const char* s, const char* t)
{
	int i;
	for (i = 0; s[i] != '\0' && t[i] != '\0'; i++) {
		if (s[i] != t[i])
			break;
	}
	if (s[i] > t[i])
		return 1;
	else if (s[i] == t[i])
		return 0;
	else
		return -1;
}

int main()
{
	char s[] = "Hello World!";
	char t[] = "hello world!";

	printf("strlen() : %u\n", strlen(s));
	printf("my_strlen() : %u\n", my_strlen(s));
	printf("my_strlen2() : %u\n", my_strlen2(s));
	printf("strcmp() : %d\n", strcmp(s, t));
	printf("my_strcmp() : %d\n", my_strcmp(s, t));
}