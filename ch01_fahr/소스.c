#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable : 4996)

void main() {
	float fahr = 0, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("fhar = %3.0f  celsius = %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

}