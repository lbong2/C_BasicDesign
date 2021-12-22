#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define BUF_SIZE 100
int main()
{
	FILE* ori;
	FILE* cp;
	char buffer[BUF_SIZE];
	int count;

	ori = fopen("Logo.png", "rb");	// 오리지날 파일 읽기모드로 오픈
	cp = fopen("copy.png", "wb");	// 카피파일 쓰기모드로 오픈
	if (ori == NULL || cp == NULL)	// 오픈 실패 시 경고문
	{
		printf("Fail to open file\n");
		return -1;
	}
	while (1)
	{
		count = fread(buffer, 1, BUF_SIZE, ori); // 오리지날 파일에서 버퍼로 데이터블록을 읽어온다.
		if (count < BUF_SIZE)	// count보다 버퍼가 크다면
		{
			if (feof(ori) != 0)	// 스트림의 eof를 검사하여 설정(set) 되어 있다면 0 이 아닌 값을 리턴한다.
			{			// 끝이 아니니 0이 아닌값을 리턴한다.
				fwrite(buffer, 1, count, cp);	// 그 때 
				printf("Copy success!!\n");
				break;
			}
			else
			{
				printf("Copy FAIL!!\n");
				break;
			}
		}
		else
		{
			fwrite(buffer, 1, BUF_SIZE, cp);	// 버퍼에 입력된 값을 cp에 쓰기
		}
	}
	fclose(ori);
	fclose(cp);
	return 0;
}