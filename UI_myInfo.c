﻿#include "header.h"



int uiShowMyInfo(Account* login) {
	int triangle;
	char ch;
	system("cls");

	gotoxy(5, 3);
	printf("=====================================================================================\n");
	gotoxy(5, 4);
	printf("\t\t\t\t\t  내 정보"); // 텝 5개 스페이스바 2개
	gotoxy(5, 5);
	printf("=====================================================================================\n");
	
	
	gotoxy(20, 7);
	printf("아이디");
	gotoxy(20, 8);
	printf("%s\t", (*login).id);

	gotoxy(40, 7);
	printf("이름");
	gotoxy(40, 8);
	printf("%s\t", (*login).name);

	gotoxy(60, 7);
	printf("닉네임");
	gotoxy(60, 8);
	printf("%s\t", (*login).nick);

	gotoxy(20, 10);
	printf("생년월일");
	gotoxy(20, 11);
	for (int i = 0; i < 8; i++) {
		printf("%d", (*login).birth[i]);
	}

	gotoxy(40, 10);
	printf("휴대폰 번호");
	gotoxy(40, 11);
	if ((*login).phone[10] == -1) {
		for (int i = 0; i < 10; i++) {
			printf("%d", (*login).phone[i]);
		}
	}
	else if ((*login).phone[11] == -1) {
		for (int i = 0; i < 11; i++) {
			printf("%d", (*login).phone[i]);
		}
	}
	

	gotoxy(60, 10);
	printf("이메일 주소");
	gotoxy(60, 11);
	printf("%s\t", (*login).email);

	gotoxy(10, 16);
	printf("┌-------------------------------┐\n");
	gotoxy(10, 17);
	printf("│           내 정보 수정        │\n");
	gotoxy(10, 18);
	printf("└-------------------------------┘\n");

	gotoxy(50, 16);
	printf("┌-------------------------------┐\n");
	gotoxy(50, 17);
	printf("│            뒤로 가기          │\n");
	gotoxy(50, 18);
	printf("└-------------------------------┘\n");


	triangle = 8;
	gotoxy(triangle, 17);
	printf("▶");
	while (1)
	{
		Sleep(300);
		if (_kbhit())
		{
			ch = _getch();
			if (ch == -32)
			{
				ch = _getch();
				switch (ch)
				{
					case LEFT:
						if (triangle > 8)
						{
							gotoxy(triangle, 17);
							printf("  ");
							triangle = triangle - 40;
							gotoxy(triangle, 17);
							printf("▶");
						}
						break;
					case RIGHT:
						if (triangle < 48)
						{
							gotoxy(triangle, 17);
							printf("  ");
							triangle = triangle + 40;
							gotoxy(triangle, 17);
							printf("▶");
						}
						break;
				}
			}
			if (ch == 13)
				break;
		}
	}


	switch (triangle)
	{
		case 8:
			if (checkPW((*login).pw) == 1) {
				selectEdit(login);
			}
			else {
				break;
			}

			break;

		case 48:
			return 2;
			break;
	}

}
