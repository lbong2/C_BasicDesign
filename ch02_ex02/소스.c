#include<stdio.h>
#pragma warning (disable : 4996)
/*
%[^\n]s << ������� �����Ͽ� �Է¹ޱ�
*/
void main() {
	char str[100];
	printf("Plz input your text : ");	//
	scanf("%[^\n]s", str);				// ������� �����Ͽ� �Է¹ޱ�
	printf("your text is : %s", str);	// ���ڿ� ���
}