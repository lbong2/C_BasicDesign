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
		ReadConsoleInput(hIn, &rec, 1, &dw);// 콘솔에서 핸들입력 받겠다 선언
		if (rec.EventType == MOUSE_EVENT)	// 인식된 동작이 마우스 이벤트라면
		{
			if (rec.Event.MouseEvent.dwButtonState &
				FROM_LEFT_1ST_BUTTON_PRESSED)	// 좌측 버튼이 눌렸을때
			{
				SetConsoleCursorPosition(hOut,
					rec.Event.MouseEvent.dwMousePosition);	// 해당 마우스 좌표에 '*'을 출력하도록 설정
				fputc('*', stdout);
				if (rec.Event.MouseEvent.dwEventFlags & DOUBLE_CLICK) // 더블클릭이 일어날 시 반복문 해제
					break;
			}
		}
	}
}