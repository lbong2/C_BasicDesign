#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)
#define MAX 100
int charCnt(unsigned char* str) {	// ���ڿ��� ���� ������ �����ϴ� �Լ�
	int len = 0;
	int spaceNum = 0;
	int punc = 0;
	while (str[len] != '\0')		// ���ڿ� ������(�ι���)�� �ƴ϶��,
	{
		
		++len;						// ���ڿ� ���� ���� (��ǻ� index)
	}
	return len;	// ���ڿ� ���̿� ����� �����ȣ�� �� �� ����
}
int wordCnt(unsigned char* str) {	// ���ڿ��� �ܾ� ������ �����ϴ� �Լ�
	int len = 0;
	int spaceNum = 0;

	while (str[len] != '\0')		// ������ ���̳��� �ʾҴٸ�,
	{
		while (str[len] == ' ') {
			spaceNum++;				// �ش�index�� ���� ������ ��� spaceNum����
			break;
		}
		++len;
	}
	return spaceNum + 1;			// sapceNum + 1�� �ܾ� ������ ����.
}
int sentenceCnt(unsigned char* str) {
	int len = 0;					// ���� ������ �����ϴ� �Լ�
	int sen_cnt = 0;
	while (str[len] != '\0')		// ���ڿ��� ������ �ʾҴٸ�,
	{
		while (str[len] == '!' || str[len] == '.' || str[len] == '?') {
			sen_cnt++;				// �ش� index�� ���� �����ȣ��� ���尳�� ����
			break;
		}
		++len;
	}
	return sen_cnt;					// ���尳�� ����
}
void analyzesen(unsigned char* str, char* buf1[]) {
	
	char* buf = (char*)malloc(sizeof(char) * 100);
	int i = 0;
	while (*str = '\0')
	{
		if (*str == '!' || *str == '.' || *str == '?')
			continue;
		
		*buf++ = *str++; 
		
		if (*str == ' ')
		{
			*buf = '\0';
			buf1[i] = buf;
			i++;
			buf = (char*)malloc(sizeof(char) * 100);
		}
		

	}
}
void main() {
	FILE* fp;
	fp = fopen("inputfile.txt", "r");
	unsigned char* str;
	str = (char*)malloc(sizeof(char) * 300);
	char** buf;
	char temp[10];
	fscanf(fp, "%[^\n]s", str);
	
	int charNum, wordNum, sentenceNum;					
	charNum = charCnt(str);								
	wordNum = wordCnt(str);								
	sentenceNum = sentenceCnt(str);						
	buf = (char**)malloc(sizeof(char*) * wordNum);
	for (int i = 0; i < wordNum; i++) {
		buf[i] = (char*)malloc(sizeof(char) * 10);
	}
	

	fclose(fp);
	for (int i = 0; i < wordNum; i++)
	{
		for (int j = i + 1; j < wordNum; j++) {
			if (strcmp(*(buf + i), *(buf + j)) == 1)	// strcmp �� �̿��ؼ� �迭 ��ü Ȯ��
			{									// ���⼭ j�� ���� index�� j�� �ִ� word�� �ƽ�Ű�ڵ������ ���� ���̶�� 
				strcpy(temp, *(buf + i));	// j�� word�� i�� word �� �ٲ۴�.
				strcpy(*(buf + i), *(buf + j));
				strcpy(*(buf + j), temp);
			}
		}
	}
	
	fp = fopen("201711242.txt", "w");
	fprintf(fp, "test i inputfile.txt o 201711242.txt\n");
	fprintf(fp, "char num : %d\nword Num : %d\nsentenceNum : %d\n", charNum, wordNum, sentenceNum);
	fclose(fp);
	for (int i = 0; i < wordNum; i++)
	{
		fprintf(fp, "%s\n", *(buf + i));
	}
	fclose(fp);
	free(str);
}