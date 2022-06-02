#include <stdio.h>
#include <string.h>
#include <Windows.h>
#pragma warning(disable: 4996)

void CursorView(char tf);
int menu();
void SignUp();
void SignIn();
void findPW();
int ID_OverlapCheck(char ID[50]);

struct person
{
	char ID[50];
	char PW[50];
};
struct person num[50];
int count = 0;

int main()
{
	system("title 회원가입 로그인");
	while (1)
	{
		int choose = menu();
		if (choose == 49)
		{
			SignUp();
		}
		else if (choose == 50)
		{
			SignIn();
		}
		else if (choose == 51)
		{
			findPW();
		}
	}
	return 0;
}

int menu()
{
	CursorView(FALSE);
	system("cls");
	int choose;
	printf("%s\n", "1) 회원가입");
	printf("%s\n", "2) 로그인");
	printf("%s\n", "3) 비밀번호 찾기");
	choose = _getch();
	CursorView(TRUE);
	return choose;
}

void SignUp()
{
	char tempID[50];
	char tempPW[50];
	char tempPW_check[50];
	system("cls");
	printf("%s", "아이디를 입력하세요 : ");
	scanf("%s", tempID);
	printf("%s", "비밀번호를 입력하세요 : ");
	scanf("%s", tempPW);
	printf("%s", "비밀번호를 다시 입력하세요 : ");
	scanf("%s", tempPW_check);
	if (strcmp(tempPW, tempPW_check) != 0)
	{
		printf("비밀번호가 다릅니다\n");
		printf("%s", "메뉴로 돌아가려면 아무키나 누르세요..");
		while (1)
		{
			if (_kbhit())
			{
				return 0;
			}
		}
	}
	if (ID_OverlapCheck(tempID) == 1)
	{
		printf("중복된 아이디가 있습니다\n");
		printf("%s", "메뉴로 돌아가려면 아무키나 누르세요..");
		while (1)
		{
			if (_kbhit())
			{
				return 0;
			}
		}
	}
	else
	{
		strcpy(num[count].ID, tempID);
		strcpy(num[count].PW, tempPW);
		printf("회원가입이 되었습니다!\n");
		printf("%s", "메뉴로 돌아가려면 아무키나 누르세요..");
		while (1)
		{
			if (_kbhit())
			{
				break;
			}
		}
		count++;
	}

}

void SignIn()
{
	system("cls");
	char ID[50];
	char PW[50];
	printf("%s", "아이디를 입력하세요 : ");
	scanf("%s", ID);
	printf("%s", "비밀번호를 입력하세요 : ");
	scanf("%s", PW);
	for (int i = 0; i <= count; i++)
	{
		if (strcmp(ID, num[i].ID) == 0 && strcmp(PW, num[i].PW) == 0)
		{
			printf("로그인이 되었습니다\n");
			printf("%s", "메뉴로 돌아가려면 아무키나 누르세요..");
			while (1)
			{
				if (_kbhit())
				{
					return 0;
				}
			}
		}
	}
	printf("아이디와 비밀번호를 다시한번 확인해주세요\n");
	printf("%s", "메뉴로 돌아가려면 아무키나 누르세요..");
	while (1)
	{
		if (_kbhit())
		{
			break;
		}
	}
}

void findPW()
{
	system("cls");
	char ID[50];
	printf("%s", "찾으실 비밀번호의 아이디를 입력하세요 : ");
	scanf("%s", ID);
	for (int i = 0; i <= count; i++)
	{
		if (strcmp(ID, num[i].ID) == 0)
		{
			printf("찾으신 비밀번호는 %s입니다\n", num[i].PW);
			printf("%s", "메뉴로 돌아가려면 아무키나 누르세요..");
			while (1)
			{
				if (_kbhit())
				{
					break;
				}
			}
		}
	}
	printf("아이디가 존재하지 않습니다\n");
	printf("%s", "메뉴로 돌아가려면 아무키나 누르세요..");
	while (1)
	{
		if (_kbhit())
		{
			break;
		}
	}
}

int ID_OverlapCheck(char ID[50])
{
	for (int i = 0; i <= count; i++)
	{
		if (strcmp(ID, num[i].ID) == 0)
		{
			return 1;
		}
	}
	return 0;
}

void CursorView(char tf)
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = tf;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
