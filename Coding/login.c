#include <stdio.h>
#include <string.h>
#include <Windows.h>
#pragma warning(disable: 4996)

int menu();
void SingUp();
void SingIn();
void findPW();

struct person
{
	char ID[50];
	char PW[50];
};
struct person num[50];
int count = 0;

int main()
{
	while (1)
	{
		int choose = menu();
		if (choose == 1)
		{
			SingUp();
		}
		else if (choose == 2)
		{
			SingIn();
		}
		else if (choose == 3)
		{
			findPW();
		}
	}
	return 0;
}

int menu()
{
	system("cls");
	int choose;
	printf("%s\n", "1) 회원가입");
	printf("%s\n", "2) 로그인");
	printf("%s\n", "3) 비밀번호 찾기");
	scanf("%d", &choose);
	return choose;
}

void SingUp()
{
	system("cls");
	printf("%s", "아이디를 입력하세요 : ");
	scanf("%s", num[count].ID);
	printf("%s", "비밀번호를 입력하세요 : ");
	scanf("%s", num[count].PW);
	count++;
}

void SingIn()
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
		if (strcmp(ID, num[i].ID) == 0 && strcmp(PW, num[i].PW == 0))
		{
			printf("로그인이 되었습니다");
			Sleep(3000);
		}
		else
		{
			printf("아이디와 비밀번호를 다시한번 확인해주세요");
			Sleep(3000);
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
			printf("찾으신 비밀번호는 %s입니다", num[i].PW);
			Sleep(3000);
			break;
		}
		printf("아이디가 존재하지 않습니다");
		Sleep(3000);
	}
}
