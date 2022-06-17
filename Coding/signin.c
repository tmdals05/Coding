#include<stdio.h>
#include<string.h>
#define MAX 100
#pragma warning(disable:4996)

void login();

char student[50][50];
char book_name[50][50];

int main()
{
	int choice;
	while (1)
	{
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			login();
		case 2:
			book_manage();
		}
	}
}

void login()
{
	char name[MAX];
	printf("당신의 이름을 입력해주세요.: ");
	scanf("%s", name);
	int j = 0, g = 0, choice;
	for (int i = 0; i < MAX;i++)
	{
		if (strcmp(name, student[i]) == 0)
		{
			if (lib[i].state == 1)
			{
				printf("%s님이 현재 대출하고 계신 책은 %s입니다.", student[i], book_name[i]);
				j = 1;
			}
			else
			{
				printf("%s님이 현재 대출하고 계신 책은 없습니다.", student[i]);
				j = 1;
			}
		}
	}
	if (j == 0)
	{
		printf("일치하는 이름이 없어 회원가입을 진행합니다. 동의하십니까?(동의시 1 입력) : ");
		scanf("%d", &choice);
		if (choice == 1)
		{
			strcpy(student[g], name);
			g++;
		}
		else
		{
			printf("가입이 취소되었습니다.");
		}
	}
}
