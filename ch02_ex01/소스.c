#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable : 4996)

#define STDNUM 96

void main() {
	int fi;
	int std[STDNUM] = { 0, };					// std[96]�迭�� �����ϰ� ������ ��� 0���� �ʱ�ȭ
	srand((unsigned)time(NULL));				// random num ����

	printf("sizeof(std[0]) = %d\n", sizeof(std[0]));	// std�迭 ��ĭ�� ũ�⸦ ��� : 4����Ʈ
	printf("sizeof(std) = %d\n", sizeof(std));			// std�迭 ��ü�� ũ�� ��� : 4 * 96 ����Ʈ
	printf("sizeof(std) / sizeof(std[0]) = %d\n", sizeof(std) / sizeof(std[0]));
														// std�迭 ��ü�� ��ĭ���� ���� ũ�� ��� : 96
	for (fi = 0; fi < STDNUM; fi++) {					// 
		std[fi] = rand() % 101;							// std�迭 �� ������ random number�� �ʱ�ȭ
		printf("student %2d's grade is %3d\n", fi, std[fi]);
	}													// ���� �迭�� ����3ĭ������ �������� ���
}