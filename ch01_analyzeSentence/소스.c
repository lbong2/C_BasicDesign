#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable : 4996)

int charCnt(unsigned char*);		//
int wordCnt(unsigned char*);		//	
int sentenceCnt(unsigned char*);	// �Լ� �����
void main() {

	unsigned char* str = "I am a boy. You are a girl.";	// string ������ �ʱ�ȭ
	int charNum, wordNum, sentenceNum;					// �� ���强�� ���� ��������
	charNum = charCnt(str);								// 
	wordNum = wordCnt(str);								//
	sentenceNum = sentenceCnt(str);						// �� ������ �Լ� ����

	printf("string = \"%s\"\n", str);

	printf("char : %d\n", charNum);
	printf("word : %d\n", wordNum);
	printf("sentence : %d\n", sentenceNum);
}
int charCnt(unsigned char* str) {	// ���ڿ��� ���� ������ �����ϴ� �Լ�
	int len = 0;
	int spaceNum = 0;
	int punc = 0;
	while (str[len] != '\0')		// ���ڿ� ������(�ι���)�� �ƴ϶��,
	{
		while (str[len] == '!' || str[len] == '.' || str[len] == '?') {
			punc++;					// �ش� index�� ���ڰ� �����ȣ��� punc�� ���� ����
			break;
		}
		while (str[len] == ' ') {
			spaceNum++;				// �ش� index�� ���ڰ� ���鹮�ڶ�� spaceNum����
			break;
		}
		++len;						// ���ڿ� ���� ���� (��ǻ� index)
	}
	return len - spaceNum - punc;	// ���ڿ� ���̿� ����� �����ȣ�� �� �� ����
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