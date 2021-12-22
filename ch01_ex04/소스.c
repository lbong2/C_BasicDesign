#include<stdio.h>

int main() {
	int i;
	int j = 0, k = 0;
	int m = 10, n = 10;

	for (i = 0; i < 10; i++) {
		printf("Increment : ++j = %2d, k++ = %2d \n", ++j, k++);
	}

	printf("\n");

	for (i = 0; i < 10; i++) {
		printf("Increment : --m = %2d, n-- = %2d \n", --m, n--);
	}
	return 0;
}