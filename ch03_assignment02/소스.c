#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)
/* 
파일 포인터로 학생 성적표 저장
*/
typedef struct student {	// 학생 구조체 선언
	char name[10];
	char classOf[10];
	int korea, math, eng;
	int sum;
	float avg;
	int rank;
}STD;

void main() {
	
	FILE* fp;
	STD std[10];
	STD tmp;

	fp = fopen("StudentScore.txt", "r");	// 파일 읽기모드로 오픈
	if (fp == NULL) printf("Failed\n");
	else printf("StudentScore read success!\n");

	for (int i = 0; i < 10; i++) {		// 텍스트파일 내의 학생 성적 및 이름 등등 읽어오는 반복문
		
		fscanf(fp, "%s", std[i].name);
		
		fscanf(fp, "%s", std[i].classOf);
		
		fscanf(fp, "%d %d %d", &std[i].korea, &std[i].math, &std[i].eng);
		std[i].sum = std[i].korea + std[i].math + std[i].eng;
		std[i].avg = (float)std[i].sum / 3.0;
		std[i].rank = 1;
	}
	fclose(fp);
	for (int i = 0; i < 10; i++) {		// 성적에 따라 rank부여
		for (int j = 0; j < 10; j++) {
			if (std[i].sum < std[j].sum) {
				std[i].rank++;
			}
		}
	}

	for (int i = 0; i < 10; i++) {		// rank에 따라 순서 배열
		for (int j = i + 1; j < 10; j++) {
			if (std[i].rank > std[j].rank) {
				tmp = std[i];
				std[i] = std[j];
				std[j] = tmp;
			}
		}
	}
	fp = fopen("StudentRank.txt", "w+");	// 성적표 파일 오픈
	if (fp == NULL) printf("Failed\n");
	for (int i = 0; i < 10; i++) {		// 성적표 구조체를 파일에 쓰는 반복문
		fprintf(fp, "================================\n");	
		fprintf(fp, "name : %s\nClass of : %s\nkorea : %d\nmath : %d\nenglish : %d\n",
			std[i].name, std[i].classOf, std[i].korea, std[i].math, std[i].eng);
		fprintf(fp, "sum : %d\naverage : %.3f\nrank : %d\n", std[i].sum, std[i].avg, std[i].rank);
		fprintf(fp, "================================\n");
	}
	printf("StudentRank write success!\n");
	fclose(fp);

}