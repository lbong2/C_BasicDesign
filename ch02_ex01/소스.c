#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable : 4996)

#define STDNUM 96

void main() {
	int fi;
	int std[STDNUM] = { 0, };					// std[96]배열을 선언하고 공간은 모두 0으로 초기화
	srand((unsigned)time(NULL));				// random num 생성

	printf("sizeof(std[0]) = %d\n", sizeof(std[0]));	// std배열 한칸의 크기를 출력 : 4바이트
	printf("sizeof(std) = %d\n", sizeof(std));			// std배열 전체의 크기 출력 : 4 * 96 바이트
	printf("sizeof(std) / sizeof(std[0]) = %d\n", sizeof(std) / sizeof(std[0]));
														// std배열 전체를 한칸으로 나눈 크기 출력 : 96
	for (fi = 0; fi < STDNUM; fi++) {					// 
		std[fi] = rand() % 101;							// std배열 각 공간을 random number로 초기화
		printf("student %2d's grade is %3d\n", fi, std[fi]);
	}													// 각각 배열의 값을3칸내에서 우측정렬 출력
}