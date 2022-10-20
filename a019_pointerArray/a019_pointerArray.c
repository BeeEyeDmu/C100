#include <stdio.h>

int main()
{
	int x = 10;
	int* ptr = &x;
	int** pptr = &ptr;
	int*** ppptr = &pptr;

	printf("%d %d %d %d\n", x, *ptr, **pptr, ***ppptr);

	char s[] = "abcd";
	char* t = "abcd";

	printf("[%p]=%s, [%p]=%s\n", s, s, t, t);

	char* p[] = { "tiger", "lion", "zebra", "giraffe", "dragon" };
	//char p[][10] = { "tiger", "lion", "zebra", "giraffe", "dragon" };

	for (int i = 0; i < 5; i++)
		printf("%s\n", p[i]);
}