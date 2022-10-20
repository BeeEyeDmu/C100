#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

void toLower(char[]);
void sortArray(char[]);
int anagram1(char*, char*);
int anagram2(char*, char*);

int main()
{
	char str1[] = "Reactive", str2[] = "Creative";

	// �� ���ڿ��� ���̸� ���մϴ�.
	if (strlen(str1) != strlen(str2))
		printf("�� ���ڿ��� ���̰� �޶� �ֳʱ׷��� �ƴմϴ�.\n");
	else {
		if(anagram1(str1, str2) == 1)
			printf("(anagram1) %s�� %s�� �ֳʱ׷��Դϴ�.\n", str1, str2);
		else
			printf("(anagram1) %s�� %s�� �ֳʱ׷��� �ƴմϴ�.\n", str1, str2);
		if (anagram2(str1, str2) == 1)
			printf("(anagram2) %s�� %s�� �ֳʱ׷��Դϴ�.\n", str1, str2);
		else
			printf("(anagram2) %s�� %s�� �ֳʱ׷��� �ƴմϴ�.\n", str1, str2);
	}
}

int anagram1(char* str1, char* str2)
{
	char* s1 = (char*)malloc(strlen(str1) + 1);
	char* s2 = (char*)malloc(strlen(str2) + 1);

	strcpy(s1, str1);
	strcpy(s2, str2);

	// �빮�ڸ� �ҹ��ڷ� �ٲߴϴ�.
	toLower(s1);
	toLower(s2);

	// ���ڿ��� ���ĺ��� �����մϴ�.
	sortArray(s1);
	sortArray(s2);

	if (!strcmp(s1, s2))
		return 1;
	else
		return 0;
}

int anagram2(char* str1, char* str2)
{
	int alpha1[26] = { 0 }, alpha2[26] = { 0 };
	char* s1 = (char*)malloc(strlen(str1) + 1);
	char* s2 = (char*)malloc(strlen(str2) + 1);

	strcpy(s1, str1);
	strcpy(s2, str2);

	// �빮�ڸ� �ҹ��ڷ� �ٲߴϴ�.
	toLower(s1);
	toLower(s2);

	while (*s1 != '\0') {
		alpha1[*s1 - 'a']++;
		alpha2[*s2 - 'a']++;
		s1++;
		s2++;
	}
	for (int i = 0; i < 26; i++)
		if (alpha1[i] != alpha2[i]) {
			return 0;
		}

	return 1;
}

void toLower(char a[])
{
	for (int c = 0; c < strlen(a) - 1; c++) {
		if (isupper(a[c]))
			a[c] = a[c] + 'a' - 'A';
	}
}

void sortArray(char a[])
{
	for (int i = 0; i < strlen(a) - 1; i++) {
		for (int j = i + 1; j < strlen(a); j++) {
			if (a[i] > a[j]) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}