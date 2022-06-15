#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

struct library
{
	int book_num; // 책 번호
	char student_name[100]; // 빌리는 학생 이름
	char book_name[100]; // 빌리는 책 이름
	int state; // 1:빌리는중, 2:반납
};
struct library lib[100];

void book_borrow(char student_name[100], int book_num, char book_name[100]); // 책빌리기
void book_return(int num, char student_name[100]); // 책 반납하기
void WaitKeyInput();

int main()
{
	for (int i = 0; i < 100; i++)
	{
		lib[i].state = 2;
	}
	while (1)
	{
		system("cls"); // 화면 초기화
		char temp_student_name[100];
		int temp_book_num;
		char temp_book_name[100];
		printf("책 대출/반납\n\n");
		printf("대출/반납할 사람의 이름을 입력해주세요 (나가려면 0입력) : ");
		scanf_s("%s", temp_student_name, (int)sizeof(temp_book_name));
		if (strcmp(temp_student_name), "0")
		printf("대출/반납할 책 번호를 입력해주세요 : ");
		scanf_s("%d", &temp_book_num);
		int IsRun = 0;
		for (int i = 0; i < 100; i++)
		{
			if (lib[i].book_num == temp_book_num && lib[i].state == 1)
			{
				book_return(i, temp_student_name, temp_book_num, temp_book_name);
				IsRun++;
				break;
			}
		}
		if (IsRun == 0)
		{
		printf("대출할 책 이름을 입력해주세요 : ");
		scanf_s(" %[^\n]s", temp_book_name, (int)sizeof(temp_book_name));
		book_borrow(temp_student_name, temp_book_num, temp_book_name);
		}
	}
}

void book_borrow(char student_name[100], int book_num, char book_name[100])
{
	for (int i = 0; i < 100; i++)
	{
		if (lib[i].state == 2)
		{
			strcpy_s(lib[i].student_name, sizeof(lib[i].student_name), student_name);
			lib[i].book_num = book_num;
			strcpy_s(lib[i].book_name, sizeof(lib[i].book_name), book_name);
			lib[i].state = 1;
			printf("\n%s님이 %s을/를 빌렸습니다", lib[i].student_name, lib[i].book_name);
			break;
		}
	}
	WaitKeyInput();
}

void book_return(int num, char student_name[100])
{
	lib[num].state = 2;
	printf("\n%s님이 %s을/를 반납했습니다", lib[num].student_name, lib[num].book_name);
	WaitKeyInput();
}

void WaitKeyInput()
{
	printf("\n계속하려면 아무키나 누르세요...");
	while (1)
	{
		if (_kbhit())
		{
			break;
		}
	}
}
