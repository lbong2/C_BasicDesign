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
		if (GetLastError() == ERROR_FILE_NOT_FOUND)	// ���� ��ȣ�� ������ ã�� �� �����ϴ�. �϶�
		{
			printf("ERROR!! COM2 PORT NOT FOUND\n");// �޽��� ���
		}
		printf("ERROR!! FAIIED TO ACCESS TO COM2 SUCCESSFULLY\n");
	}

	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	if (!GetCommState(hSerial, &dcbSerialParams))
	{
		printf("ERROR!! FAIIED TO GET SERIAL PARAMETERS\n");
	}

	dcbSerialParams.BaudRate = CBR_57600;	// ��Ʈ���ᰣ �ʿ��� ���� ����
	dcbSerialParams.ByteSize = 8;
	dcbSerialParams.Parity = NOPARITY;
	dcbSerialParams.StopBits = ONESTOPBIT;

	if (!SetCommState(hSerial, &dcbSerialParams)) // ��Ʈ ������ �߸��Ǽ� ������ �����ʾ��� ��
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
			c = getchar();	// ������ ���ڸ� �д´� (1��)
			if (c == '\0')	// �ܾ� Ȥ�� ���ڿ��� ���� �ν�(enter�Է����� ����)
			{
				break;
			}
			else // ���ڿ��� ���� �ƴ϶�� puTTYâ�� ���ڸ� ����Ѵ�.
			{
				WriteFile(hSerial, &c, 1, &bytes_written, NULL);
			}
			
		}
	}

	CloseHandle(hSerial);
	return 0;
}