#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable : 4996)

int sumAB(int a, int b);
int mulAB(int a, int b);
int main() {
	int a, b, n, result;
	while (1) {
		printf("1: ADD, 2:MUL, 3:quit\n");
		scanf("%d", &n);
		if (n == 3)
			break;
		printf("a : ");
		scanf("%d", &a);
		printf("b : ");
		scanf("%d", &b);
		switch (n) {
		case 1:
			result = sumAB(a, b);
			printf("%d + %d = %d\n\n", a, b, result);
			break;
		case 2:
			result = mulAB(a, b);
			printf("%d * %d = %d\n\n", a, b, result);
			break;
		default: break;
		}
		
	}
	return 0;

}
int sumAB(int a, int b) {
	return a + b;
}
int mulAB(int a, int b) {
	return a * b;
}