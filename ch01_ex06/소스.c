#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable : 4996)
int main() {
	int a, b;
	srand((unsigned)time(NULL));
	a = rand() % 100 + 1;
	while (1) {
		printf("user >> ");
		scanf("%d", &b);
		if (a == b) {
			printf("\t a(%d) = %d \n", a, b);
			break;
		}
		else if (a > b) {
			printf("\t a > %d \n", b);
		}
		else if (a < b) {
			printf("\t a < %d \n", b);
		}
	}
	return 0;
}