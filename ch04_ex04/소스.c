#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	char c;
	HANDLE hSerial;
	unsigned long bytes_written;
	DCB dcbSerialParams = { 0 };
	COMMTIMEOUTS timeouts = { 0 };

	hSerial = CreateFile(L"COM2", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hSerial == INVALID_HANDLE_VALUE)
	{
		if (GetLastError() == ERROR_FILE_NOT_FOUND)	// 에러 신호가 파일을 찾을 수 없습니다. 일때
		{
			printf("ERROR!! COM2 PORT NOT FOUND\n");// 메시지 출력
		}
		printf("ERROR!! FAIIED TO ACCESS TO COM2 SUCCESSFULLY\n");
	}

	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	if (!GetCommState(hSerial, &dcbSerialParams))
	{
		printf("ERROR!! FAIIED TO GET SERIAL PARAMETERS\n");
	}

	dcbSerialParams.BaudRate = CBR_57600;	// 포트연결간 필요한 정보 기입
	dcbSerialParams.ByteSize = 8;
	dcbSerialParams.Parity = NOPARITY;
	dcbSerialParams.StopBits = ONESTOPBIT;

	if (!SetCommState(hSerial, &dcbSerialParams)) // 포트 정보가 잘못되서 연결이 되지않았을 때
	{
		printf("ERROR, Setting serial port state");
	}

	timeouts.ReadIntervalTimeout = 50;
	timeouts.ReadTotalTimeoutConstant = 50;
	timeouts.ReadTotalTimeoutMultiplier = 10;
	timeouts.WriteTotalTimeoutConstant = 50;
	timeouts.WriteTotalTimeoutMultiplier = 10;


	if (!SetCommTimeouts(hSerial, &timeouts))
	{
		printf("ERROR!! Time Out\n");
		return 1;
	}
	else
	{
		while (1)
		{
			c = getchar();	// 버퍼의 문자를 읽는다 (1개)
			if (c == '\0')	// 단어 혹은 문자열의 끝을 인식(enter입력으로 인한)
			{
				break;
			}
			else // 문자열의 끝이 아니라면 puTTY창에 문자를 출력한다.
			{
				WriteFile(hSerial, &c, 1, &bytes_written, NULL);
			}
			
		}
	}

	CloseHandle(hSerial);
	return 0;
}