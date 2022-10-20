#include <stdio.h>

int main()
{
	char s[10] = { 'a', 'b', 'c', 'd', 'e' };
	char t[] = { 'a', 'b', 'c', 'd', 'e', '\0' };
	char u[] = "abcde";
	char v[] = "æ»≥Á«œººø‰";

	printf("s = |%s| size = %d\n", s, sizeof(s));
	printf("t = |%s| size = %d\n", t, sizeof(t));
	printf("u = |%s| size = %d\n", u, sizeof(u));
	printf("v = |%s| size = %d\n", v, sizeof(v));
}