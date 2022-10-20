#include <stdio.h>
#include <string.h>
#include <malloc.h>

// source에서 dest로 문자열 복사
char* my_strcpy(char* dest, char* source)
{
	dest = (char*)malloc(strlen(source) + 1);
	int i = 0;
	while (dest[i] = source[i])
		i++;
	dest[i] = '\0';
	return dest;
}

// src에 dest 문자열을 결합
char* my_strcat(char* dest, char* src)
{
	char* result = (char*)malloc(strlen(dest) + strlen(src) + 1);
	int i = 0;

	while (dest[i] != '\0') {
		result[i] = dest[i];
		i++;
	}

	char* ptr = result + strlen(dest);
	while (*src != '\0')
		*ptr++ = *src++;
	*ptr = '\0';

	return result;
}

int main()
{
	char s[] = "Hello World!";
	char t[] = "hello world!";
	char u[] = "C programming language!";

	my_strcpy(s, t);
	printf("my_strcpy() : %s->%s\n", s, t);

	my_strcpy(s, u);
	printf("my_strcat() : %s\n", my_strcat(s, u));
}