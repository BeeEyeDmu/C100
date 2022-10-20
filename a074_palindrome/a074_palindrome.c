#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

void iPalindrome(int n);
void sPalindrome(char* s);
void toLower(char* s);
void removeSpace(char* s);

int main()
{
	int n;
	char s[80];

	printf("Enter an integer: ");
	scanf("%d", &n);
	getchar();	// new line을 읽기 위해서 필요함
	iPalindrome(n);

	printf("Enter a string: ");
	fgets(s, 80, stdin);
	sPalindrome(s);
}

void iPalindrome(int n)
{
	int originalN = n;
	int reversedN = 0;
	int rem;

	while (n != 0) {
		rem = n % 10;
		reversedN = reversedN * 10 + rem;
		n /= 10;
	}

	if (originalN == reversedN)
		printf(" -> %d is a palindrome.\n", originalN);
	else
		printf(" -> %d is not a palindrome.\n", originalN);
}

void sPalindrome(char* s)
{
	int i, k = 0;
	int left, right;

	removeSpace(s);  // 공백문자를 제거합니다
	toLower(s);      // 대문자를 소문자로 바꿉니다

	left = 0;
	right = strlen(s) - 1;
	while (left < right) {
		if (s[left++] != s[right--]) {
			printf(" -> %s is not a palindrome.\n", s);
			return;
		}
	}
	printf(" -> %s is a palindrome.\n", s);
}

void toLower(char* s)
{
	while (*s) {
		if (isupper(*s))
			*s = *s - 'A' + 'a';
		s++;
	}
}

void removeSpace(char* s)
{
	int i, k;

	for (i = 0, k = 0; s[i + k]; i++) {
		s[i] = s[i + k];
		if (isspace(s[i])) {
			k++;
			i--;
		}
	}
	s[i] = '\0';
}