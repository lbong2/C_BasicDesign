#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable : 4996)

int main() {
	int random, guess;
	srand((unsigned)time(NULL));

	random = rand() % 100 + 1;

	printf("=========Up & Down prediction==========\n");
	printf("type your guess(1~100) : ");
	scanf("%d", &guess);

	while (guess != random) {
		printf("Wrong answer!      ");
		while (guess > random) { printf("Down\n"); break; }
		while (guess < random) { printf("Up\n"); break; }

		printf("type your guess(1~100) : ");
		scanf("%d", &guess);
	}

	printf("correct! Game Over");
}