#include <stdio.h>
#include <stdlib.h>
#define YEARS 4
#define STUDENTS 10
#define SUBJECTS 10

void randomScore(int score[][STUDENTS][SUBJECTS])
{
	for (int i = 0; i < YEARS; i++)
		for (int j = 0; j < STUDENTS; j++)
			for (int k = 0; k < SUBJECTS; k++)
				score[i][j][k] = rand() % 101;
}

void printScore(int score[][STUDENTS][SUBJECTS])
{
	for (int i = 0; i < YEARS; i++) {
		printf("\n%d학년\n", i + 1);
		for (int j = 0; j < STUDENTS; j++) {
			printf("학생%2d ", j + 1);
			for (int k = 0; k < SUBJECTS; k++) {
				printf("%4d", score[i][j][k]);
			}
			printf("\n");
		}
	}
}

void highestScore(int score[][STUDENTS][SUBJECTS])
{
	int max = 0;
	struct highest {
		int year;
		int student;
		int subject;
	} highest;

	for (int i = 0; i < YEARS; i++)
		for (int j = 0; j < STUDENTS; j++)
			for (int k = 0; k < SUBJECTS; k++)
				if (max < score[i][j][k]) {
					max = score[i][j][k];
					highest.year = i + 1;
					highest.student = j + 1;
					highest.subject = k + 1;
				}

	printf("Highest Score : %d학년, 학생%2d, 과목 %2d = %d점\n",
		highest.year, highest.student, highest.subject, max);
}

// 학년별 평균이 가장 높은 과목
void highestSubject(int score[][STUDENTS][SUBJECTS])
{
	int sum[YEARS][SUBJECTS];

	for (int i = 0; i < YEARS; i++) {
		for (int k = 0; k < SUBJECTS; k++) {
			sum[i][k] = 0;
			for (int j = 0; j < STUDENTS; j++)
				sum[i][k] += score[i][j][k];
		}
	}

	// 각 과목의 총점과 가장 점수가 높은 과목을 출력
	for (int i = 0; i < YEARS; i++) {
		printf("%d학년 과목별 총점\n", i + 1);
		int bestScore = 0;
		int bestIndex = 0;
		for (int j = 0; j < SUBJECTS; j++) {
			printf("%4d", sum[i][j]);
			if (bestScore < sum[i][j]) {
				bestScore = sum[i][j];
				bestIndex = j;
			}
		}
		printf("\n");
		printf(" 가장 높은 점수의 과목 = %d, 과목 총점 = %d\n",
			bestIndex + 1, bestScore);
	}
}

int main()
{
	int score[YEARS][STUDENTS][SUBJECTS];

	randomScore(score);
	printScore(score);
	highestScore(score);
	highestSubject(score);
}