#include <stdio.h>
#include <string.h>

char str[] = "ababacabcaab";
char sub[] = "abc";

// 문자열 str에서 sub 문자열이 처음 시작되는 포인터를 리턴합니다.
char* my_strstr(const char* str, const char* sub)
{
	int len1 = strlen(str);
	int len2 = strlen(sub);

	if (len2 == 0)	// sub 문자열이 ""라면 무조건 매칭된다고 가정
		return (char*)str;

	// str의 남은 길이가 sub보다 작다면 비교할 필요가 없으므로 NULL을 리턴
	while (len1 >= len2) {
		char* s = (char*)str;
		char* t = (char*)sub;
		while (*s == *t && *t != NULL) {
			s++;
			t++;
		}
		if (*t == NULL)
			return (char*)str;
		str++;
		len1--;
	}
	return NULL;
}

int main()
{
	printf("strstr() : %s\n", strstr(str, sub));
	printf("my_strstr() : %s\n", my_strstr(str, sub));
}