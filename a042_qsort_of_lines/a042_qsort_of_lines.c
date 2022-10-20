#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAXLINES	1000    // 입력 라인수
#define MAXLEN		1000    // 한 라인의 문자수

char* lineptr[MAXLINES] = { NULL };

void writelines(char* lineptr[])
{
	char** ptr = lineptr;

	while (*ptr)
		printf("%s\n", *(ptr++));
}

void swap(char* v[], int i, int j)
{
	char* tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

void my_qsort(char* v[], int left, int right)
{
	int i, last;

	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);

	swap(v, left, last);

	my_qsort(v, left, last - 1);
	my_qsort(v, last + 1, right);
}

int main()
{
	int nlines = 0;
	char line[MAXLEN];

	printf("문장을 입력하세요(입력을 끝낼 때는 [Enter] 키를 누르세요) :\n");
	while (fgets(line, MAXLEN, stdin) != NULL) {
		if (!strcmp(line, "\n"))
			break;
		line[strlen(line) - 1] = '\0';
		lineptr[nlines] = (char*)malloc(strlen(line) + 1);
		if (lineptr[nlines] != NULL)
			strcpy(lineptr[nlines], line);
		nlines++;
	}
	my_qsort(lineptr, 0, nlines - 1);
	printf("\n ... after sorting ...\n");
	writelines(lineptr);
}