#include<stdio.h>

int main() {
	printf("Data types and sizes \n\n");
	printf(" char = %d bytes \n int = %d bytes\n", sizeof(char), sizeof(int));
	printf(" short = %d bytes \n long = %d bytes\n", sizeof(short), sizeof(long));
	printf(" float = %d bytes \n double = %d bytes\n", sizeof(float), sizeof(double));

	return 0;
}