#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable : 4996)

void statistic(int* arr, int arr_size, float* avr, int* max, int* min) {
	float sum = 0;
	int fi = 0;
	*min = INT_MAX;
	*max = INT_MIN;

}
int main(int argc, char *argv[]) {
	int N = 0;
	int* ptr = NULL;
	float avr = 0;
	int max = 0;
	int min = 0;
	int fi;

	srand((unsigned)time(NULL));

	if (argc < 2)
	{
		printf("CHK cmd Input!!!\n");
		return -1;
	}

	N = atoi(argv[1]);

	if (N < 1) {
		printf("CHK cmd Input!!!\n");
		return -1;
	}

	printf("N = %d\n", N);

	printf("Average : %f\n", avr);
	printf("max : %d\n", max);
	printf("min : %d\n", min);
	free(ptr);
	return 0;
}