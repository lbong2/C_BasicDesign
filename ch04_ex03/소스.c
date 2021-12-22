#include <Windows.h>
#include <stdio.h>

int main(void)
{
	HANDLE hIn, hOut;
	INPUT_RECORD rec;
	DWORD dw;

	hIn = GetStdHandle(STD_INPUT_HANDLE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(hIn, Mode))
		printf("ERROR at SetConsoleMode\n");
	Mode = ENABLE_WINDOW_INPUT |
		ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hIn, Mode))
		printf("ERROR at SetConsoleMode\n");
	

	while (1)
	{
		ReadConsoleInput(hIn, &rec, 1, &dw);// �ֿܼ��� �ڵ��Է� �ްڴ� ����
		if (rec.EventType == MOUSE_EVENT)	// �νĵ� ������ ���콺 �̺�Ʈ���
		{
			if (rec.Event.MouseEvent.dwButtonState &
				FROM_LEFT_1ST_BUTTON_PRESSED)	// ���� ��ư�� ��������
			{
				SetConsoleCursorPosition(hOut,
					rec.Event.MouseEvent.dwMousePosition);	// �ش� ���콺 ��ǥ�� '*'�� ����ϵ��� ����
				fputc('*', stdout);
				if (rec.Event.MouseEvent.dwEventFlags & DOUBLE_CLICK) // ����Ŭ���� �Ͼ �� �ݺ��� ����
					break;
			}
		}
	}
}