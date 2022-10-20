#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 	// strcpy_s() 함수
#include <math.h>	 	// pow() 함수
#include <ctype.h>	 	// isdigit() 함수

#define MINUS -1
#define PLUS 1

double my_atof(char* s)
{
	int sign = PLUS;		// 부호
	int value = 0;			// 정수부(significand)
	double mantissa = 0;	// 가수부(mantissa)
	double mandigit = 10;	// 가수부의 자리수
	int exp = 0;			// 지수부(exponent)
	int expsign = PLUS;	// 지수부 부호

	if (*s == '-') {		// 부호처리
		sign = MINUS;
		s++;
	}
	else {
		if (*s == '+')
			s++;
	}

	// 소수점까지 읽기(정수부) 
	while (*s != '.' && *s != 'E' && *s != 'e' && *s != NULL) {
		if (isdigit(*s))
			value = value * 10 + (*s - '0');
		s++;
	}

	// 가수부(mantissa)
	if (*s == '.') {	// 지금부터 가수부
		while (*s != 'E' && *s != 'e' && *s != NULL) {
			if (isdigit(*s)) {
				mantissa = mantissa + (*s - '0') / mandigit;
				mandigit *= 10;
			}
			s++;
		}
	}

	// 지수부(exponent) 부호 처리
	if (*s == 'e' || *s == 'E') {
		s++;
		if (*s == '-') {			// 부호처리
			expsign = MINUS;
			s++;
		}
		else {
			if (*s == '+')
				s++;
		}
	}
	// 지수부 숫자 읽기
	while (*s != NULL) {
		if (isdigit(*s)) {
			exp = exp * 10 + (*s - '0');
			s++;
		}
	}
	return sign * (value + mantissa) * pow(10, expsign * exp);
}

int main()
{
	char s[30] = "1.234";

	printf("%f\n", my_atof(s));

	strcpy(s, "1.234e10");
	printf("%e\n", my_atof(s));

	strcpy(s, "-1.234E-10");
	printf("%e\n", my_atof(s));
}