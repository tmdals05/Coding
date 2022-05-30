#include <stdio.h>
#include <Windows.h>
#include <conio.h>

int menu();
void game();
void setting();
void map_print();
int check_5line();
void CursorView(char tf);

int board_size_x = 19;
int board_size_y = 19;
int map[53][53] = {0};
char alphabet[52] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
					  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main()
{
	system("title 배똥의 오목게임!!");
	while (1)
	{
		int choice = menu();
		if (choice == 49)
		{
			game();
		}
		else if (choice == 50)
		{
			setting();
		}
		else if (choice == 51)
		{
			return 0;
		}
	}
}

int menu()
{
	CursorView(FALSE);
	int choice;
	system("cls");
	printf("배똥의 오목게임\n");
	printf("1) 시작\n");
	printf("2) 바둑판 크기 설정\n");
	printf("3) 나가기\n");
	choice = _getch();
	system("cls");
	CursorView(TRUE);
	return choice;
}

void game()
{
	int x_coordinate;
	int y_coordinate;
	int turn = 0;
	while (1)
	{
		map_print();

		if (turn % 2 == 0)
		{
			printf("흑돌 차례입니다\n");
		}
		else if (turn % 2 == 1)
		{
			printf("백돌 차례입니다\n");
		}

		printf("%s", "좌표를 입력하시오 : ");
		scanf_s("%d %d", &x_coordinate, &y_coordinate);

		if (turn % 2 == 0)
		{
			map[x_coordinate][y_coordinate] = 1;
		}
		else if (turn % 2 == 1)
		{
			map[x_coordinate][y_coordinate] = 2;
		}

		if (check_5line() == 1)
		{
			printf("%s", "\n흑돌이 이겼습니다!\n");
			break;
		}
		else if (check_5line() == 2)
		{
			printf("%s", "\n백돌이 이겼습니다!\n");
			break;
		}
		else if (check_5line() == 0)
		{
			turn++;
		}
	}
	CursorView(FALSE);
	printf("%s", "계속하려면 아무키나 누르세요");
	while (1)
	{
		if (_kbhit())
		{
			break;
		}
	}
}

void setting()
{
	int temp_x = board_size_x;
	int temp_y = board_size_y;
	while (board_size_x != 0 && board_size_y != 0)
	{
	size_scan:
		system("cls");
		printf("설정\n\n");
		printf("바둑판 크기 : %d×%d\n", board_size_x, board_size_y);
		printf("기본값 : 19×19\n");
		printf("최솟값 : 10×10\n");
		printf("최댓값 : 52×52\n");
		printf("ex) 10 10\n");
		printf("나가기 : 0 0입력\n");
		scanf_s("%d %d", &board_size_x, &board_size_y);
		if (board_size_x == 0 && board_size_y == 0)
		{
			board_size_x = temp_x;
			board_size_y = temp_y;
			break;
		}
		else if (board_size_x < 10 || board_size_y < 10)
		{
			printf("%s", "\n입력한 값이 최솟값보다 작습니다\n");
			board_size_x = temp_x;
			board_size_y = temp_y;
			Sleep(1000);
			goto size_scan;
		}
		else if (board_size_x > 52 || board_size_y > 52)
		{
			printf("%s", "\n입력한 값이 최댓값보다 큽니다\n");
			board_size_x = temp_x;
			board_size_y = temp_y;
			Sleep(1000);
			goto size_scan;
		}
		else
		{
			temp_x = board_size_x;
			temp_y = board_size_y;
		}
	}
}

void map_print()
{
	system("cls");
	printf("%s\n\n", "바둑판");
	printf("  ");
	for (int i = 0; i != board_size_x; i++)
	{
		printf("%c ", alphabet[i]);
	}
	printf("\n");
	for (int i = 1; i != board_size_x + 1; i++)
	{
		printf("%c", alphabet[i - 1]);
		for (int j = 1; j != board_size_y + 1; j++)
		{
			if (map[i][j] == 0)
			{
				printf("%s", "◎");
			}
			else if(map[i][j] == 1)
			{
				printf("%s", "□");
			}
			else if (map[i][j] == 2)
			{
				printf("%s", "■");
			}
		}
		printf("\n");
	}
	printf("\n");
}

int check_5line()
{
	return 2;
}

void CursorView(char tf)
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = tf;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
