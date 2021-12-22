#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning (disable : 4996)

int main()
{
	POINT a;
	char c;
	unsigned long bytes_written;
	HANDLE hIn, hOut;
	INPUT_RECORD rec;
	DWORD dw;
	int x, y;
	int cnt;
	
	hIn = GetStdHandle(STD_INPUT_HANDLE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	
	HANDLE hSerial;
	unsigned long bytes_read;
	DCB dcbSerialParams = { 0 };
	COMMTIMEOUTS timeouts = { 0 };

	hSerial = CreateFile(L"COM2", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hSerial == INVALID_HANDLE_VALUE)
	{
		if (GetLastError() == ERROR_FILE_NOT_FOUND)
		{
			printf("ERROR!! COM2 PORT NOT FOUND\n");
		}
		printf("ERROR!! FAIIED TO ACCESS TO COM2 SUCCESSFULLY\n");
	}

	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);


	if (!GetCommState(hSerial, &dcbSerialParams))
	{
		printf("ERROR!! FAIIED TO GET SERIAL PARAMETERS\n");
	}

	dcbSerialParams.BaudRate = CBR_57600;
	dcbSerialParams.ByteSize = 8;
	dcbSerialParams.Parity = NOPARITY;
	dcbSerialParams.StopBits = ONESTOPBIT;

	if (!SetCommState(hSerial, &dcbSerialParams))
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
		DWORD Mode = ENABLE_EXTENDED_FLAGS;
		if (!SetConsoleMode(hIn, Mode))
			printf("ERROR at SetConsoleMode\n");
		Mode = ENABLE_WINDOW_INPUT |
			ENABLE_MOUSE_INPUT;
		if (!SetConsoleMode(hIn, Mode))
			printf("ERROR at SetConsoleMode\n");
		
		while (1)
		{
			int tmp = 0;	// �ӽ� ���� 
			cnt = 0;	// ���� ����
			GetCursorPos(&a);
			
			WriteFile(hSerial, "Xpos = ", 7, &bytes_written, NULL);	
			sprintf(&c, "%04d", a.x);		// ���콺 ��ǥ�� str���·� ��ȯ
			WriteFile(hSerial, &c, 4, &bytes_written, NULL); // ��ȯ�� c�� ���
			WriteFile(hSerial, "Ypos = ", 7, &bytes_written, NULL);
			sprintf(&c, "%04d", a.y);		// ���콺 ��ǥ�� str ���·� ��ȯ
			WriteFile(hSerial, &c, 4, &bytes_written, NULL); // ��ȯ�� c�� ���
			WriteFile(hSerial, "\n\r", 2, &bytes_written, NULL);// �ٹٲ�, Ŀ�� ������
			ReadConsoleInput(hIn, &rec, 1, &dw);

				if (rec.EventType == MOUSE_EVENT) {	// ���콺 �ν� ����
					
					if (rec.Event.MouseEvent.dwEventFlags & DOUBLE_CLICK)	// ����Ŭ���� �ԷµǸ�
					{
						WriteFile(hSerial, "Double Click!!\n\r", 16, &bytes_written, NULL);

						WriteFile(hSerial, "Xpos = ", 7, &bytes_written, NULL);
						while (cnt < 4)
						{
						
							ReadFile(hSerial, &c, 1, &bytes_read, NULL);
							if (bytes_read == 1) {
								cnt++;
								tmp = tmp * 10 + c - '0';	// �Է� ���� char�� �ٷ� ������ ��ȯ

							}
						}
						x = tmp;	// x�� ��ȯ�� ���� �ʱ�ȭ
						WriteFile(hSerial, "\n\r", 2, &bytes_written, NULL); 
						cnt = 0;
						tmp = 0;
						WriteFile(hSerial, "Ypos = ", 7, &bytes_written, NULL);
						while (cnt < 4)
						{
							ReadFile(hSerial, &c, 1, &bytes_read, NULL);
							if (bytes_read == 1) {
								cnt++;
								tmp = tmp * 10 + c - '0';	// �Է� ���� char�� �ٷ� ������ ��ȯ

							}
						}
						y = tmp;	// y�� ��ȯ�� ���� �ʱ�ȭ
						WriteFile(hSerial, "\n\r", 2, &bytes_written, NULL); 
						SetCursorPos(x, y); // �ʱ�ȭ�� ��ǥ�� �̵�
					}
					
				}
				
		}
	}

	CloseHandle(hSerial);
	return 0;
}