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
		int p = (i - 1) / 2; // �θ� �ε���
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
	int root = pq[count - 1];  // �� ������ ����
	count--;

	// downheap
	int i = 0;
	while (i * 2 + 1 < count) { // ������尡 �� ������
		pq[i] = root;
		int left = i * 2 + 1;
		int right = i * 2 + 2;
		int c;
		if (right < count && pq[right] > pq[left])
			c = right;
		else
			c = left;

		if (pq[c] > pq[i]) {  // �� ��带 �ٲ۴�
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

	printf("�� ���� ������ : ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("������ %d : ", i + 1);
		scanf("%d", &d);
		insert(d);
	}
	printPQ();

	printf("�� ��° ū �� : ");
	scanf("%d", &k);

	for (int i = 0; i < k - 1; i++)
		remove();
	printf("%d��° ū �� = %d\n", k, remove());
}