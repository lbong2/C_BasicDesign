#include<stdio.h>
#pragma warning (disable : 4996)
/* 
�л� ����ǥ
*/
typedef struct student {	//�л� ����ü ���� ����� ����
	char name[10];
	char classOf[10];
	int korea, math, eng;
	int sum;
	float avg;
	int rank;
}STD;

void main() {
	STD std[10];		//����ü �迭 ����
	STD tmp;

	for (int i = 0; i < 10; i++) {	// ����ü�� �������� �ʱ�ȭ�ϴ� �ݺ���
		printf("Plz input name of student%d : ", i + 1);
		scanf("%s", std[i].name);
		printf("Plz input class of student : ");
		scanf("%s", std[i].classOf);
		printf("Plz input score of korea, math, english : ");
		scanf("%d %d %d", &std[i].korea, &std[i].math, &std[i].eng);
		std[i].sum = std[i].korea + std[i].math + std[i].eng;
		std[i].avg = (float)std[i].sum / 3.0;
		std[i].rank = 1;
	}
	for (int i = 0; i < 10; i++) {	// ����ü ���� rank������ ������ ���� �����ϴ� �ݺ���
		for (int j = 0; j < 10; j++) {
			if (std[i].sum < std[j].sum) {
				std[i].rank++;
			}
		}
	}
	for (int i = 0; i < 10; i++) {	// ����ü ���� rank�� ���� ������ ��ġ�ϴ� �ݺ���
		for (int j = i + 1; j < 10; j++) {
			if (std[i].rank > std[j].rank) {
				tmp = std[i];
				std[i] = std[j];
				std[j] = tmp;
			}
		}
	}

	for (int i = 0; i < 10; i++) {	// ����ǥ ���
		printf("================================\n");
		printf("name : %s\nClass of : %s\nkorea : %d\nmath : %d\nenglish : %d\n", 
			std[i].name, std[i].classOf, std[i].korea, std[i].math, std[i].eng);
		printf("sum : %d\naverage : %.3f\nrank : %d\n", std[i].sum, std[i].avg, std[i].rank);
		printf("================================\n");
	}
}