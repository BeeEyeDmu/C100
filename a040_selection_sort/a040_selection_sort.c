#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX	 30

void swap(int v[], int i, int j)
{
	int tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

void selection_sort(int v[], int left, int right)
{
	for (int i = left; i < right - 1; i++) {
		int min = i;
		for (int j = i + 1; j < right; j++)
			if (v[min] > v[j])
				min = j;
		swap(v, i, min);
	}
}

int main()
{
	int v[MAX];

	srand(time(0));
	for (int i = 0; i < MAX; i++)
		v[i] = rand();

	for (int i = 0; i < MAX; i++)
		printf("%6d %c", v[i], (i + 1) % 10 == 0 ? '\n' : ' ');

	selection_sort(v, 0, MAX);

	printf("\n...selection sorting\n");
	for (int i = 0; i < MAX; i++)
		printf("%6d %c", v[i], (i + 1) % 10 == 0 ? '\n' : ' ');
}