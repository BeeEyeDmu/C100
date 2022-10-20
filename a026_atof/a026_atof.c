#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 	// strcpy_s() �Լ�
#include <math.h>	 	// pow() �Լ�
#include <ctype.h>	 	// isdigit() �Լ�

#define MINUS -1
#define PLUS 1

double my_atof(char* s)
{
	int sign = PLUS;		// ��ȣ
	int value = 0;			// ������(significand)
	double mantissa = 0;	// ������(mantissa)
	double mandigit = 10;	// �������� �ڸ���
	int exp = 0;			// ������(exponent)
	int expsign = PLUS;	// ������ ��ȣ

	if (*s == '-') {		// ��ȣó��
		sign = MINUS;
		s++;
	}
	else {
		if (*s == '+')
			s++;
	}

	// �Ҽ������� �б�(������) 
	while (*s != '.' && *s != 'E' && *s != 'e' && *s != NULL) {
		if (isdigit(*s))
			value = value * 10 + (*s - '0');
		s++;
	}

	// ������(mantissa)
	if (*s == '.') {	// ���ݺ��� ������
		while (*s != 'E' && *s != 'e' && *s != NULL) {
			if (isdigit(*s)) {
				mantissa = mantissa + (*s - '0') / mandigit;
				mandigit *= 10;
			}
			s++;
		}
	}

	// ������(exponent) ��ȣ ó��
	if (*s == 'e' || *s == 'E') {
		s++;
		if (*s == '-') {			// ��ȣó��
			expsign = MINUS;
			s++;
		}
		else {
			if (*s == '+')
				s++;
		}
	}
	// ������ ���� �б�
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