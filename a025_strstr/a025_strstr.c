#include <stdio.h>
#include <string.h>

char str[] = "ababacabcaab";
char sub[] = "abc";

// ���ڿ� str���� sub ���ڿ��� ó�� ���۵Ǵ� �����͸� �����մϴ�.
char* my_strstr(const char* str, const char* sub)
{
	int len1 = strlen(str);
	int len2 = strlen(sub);

	if (len2 == 0)	// sub ���ڿ��� ""��� ������ ��Ī�ȴٰ� ����
		return (char*)str;

	// str�� ���� ���̰� sub���� �۴ٸ� ���� �ʿ䰡 �����Ƿ� NULL�� ����
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