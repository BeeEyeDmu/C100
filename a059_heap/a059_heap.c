#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pq[100] = { 0 };
int count = 0;

void printPQ()
{
	for (int i = 0; i < count; i++)
		printf("%5d", pq[i]);
	printf("\n");
}

void insert(int x)
{
	int i = count;
	pq[count++] = x;

	// upheap
	while (i > 0) {
		int p = (i - 1) / 2; // 부모 인덱스
		if (pq[p] >= x)
			break;
		pq[i] = pq[p];
		i = p;
	}
	pq[i] = x;
}

int remove()
{
	int max = pq[0];
	int root = pq[count - 1];  // 맨 마지막 원소
	count--;

	// downheap
	int i = 0;
	while (i * 2 + 1 < count) { // 리프노드가 될 때까지
		pq[i] = root;
		int left = i * 2 + 1;
		int right = i * 2 + 2;
		int c;
		if (right < count && pq[right] > pq[left])
			c = right;
		else
			c = left;

		if (pq[c] > pq[i]) {  // 두 노드를 바꾼다
			int t = pq[c];
			pq[c] = pq[i];
			pq[i] = t;
			i = c;
		}
		else
			break;
	}
	return max;
}

int main()
{
	int n, d, k;

	printf("몇 개의 데이터 : ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("데이터 %d : ", i + 1);
		scanf("%d", &d);
		insert(d);
	}
	printPQ();

	printf("몇 번째 큰 값 : ");
	scanf("%d", &k);

	for (int i = 0; i < k - 1; i++)
		remove();
	printf("%d번째 큰 값 = %d\n", k, remove());
}