#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable : 4996)

int strlen(unsigned char str[]);
void main() {
	int len;
	unsigned char* str = "Some where over the rainbow";

	printf("strlen = return length of string\n");
	printf("string = \"%s\"\n", str);
	len = strlen(str);

	printf("strlen : %d\n", len);

}
int strlen(unsigned char str[]) {
	int i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return i;
}