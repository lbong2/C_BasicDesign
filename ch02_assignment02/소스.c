#include<stdio.h>
#pragma warning (disable : 4996)
/*
�Է¹��� ���ڿ� ���鰳�� ���
*/
#define INDEX 1001			// �ִ� 1000�ڸ� ���� �� �־�� �ϱ⶧���� ('\0')
int main() {
	char str[INDEX];
	int spaceNum = 0;
	int i = 0;
	printf("Plz Input your text >> ");
	scanf("%[^\n]s", &str);	// ���� ���� �Է� ����

	while (str[i] != '\0') {// �迭�� NULL���ڸ� ������ �Է��� ���ڿ� +1 ��ŭ �ʿ��� 
		if (str[i] == ' ')	// �迭�� ������ �ִٸ�		
			spaceNum++;		// ���� ���� ���� ����
		i++;
	}
	printf("%s have %d space\n", str, spaceNum); // ���� ���� ���
	return 0;
}
