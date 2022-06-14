#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

struct library
{
	int book_num; // 책 번호
	int student_num; // 빌리는 학생 번호
	char book_name[100]; // 빌리는 책 이름
	int state; // 1:빌리는중, 2:반납
};
struct library lib[100];

void book_borrow(int student_num, int book_num, char book_name[100]); // 책빌리기
void book_return(int num, int student_num, int book_num, char book_name[100]); // 책 반납하기
void WaitKeyInput();

int main()
{
start:
	system("cls"); // 화면 초기화
	int temp_student_num;
	int temp_book_num;
	char temp_book_name[100];
	printf("책 대출/반납\n\n");
	printf("대출할 사람의 번호를 입력해주세요 : ");
	scanf_s("%d", &temp_student_num);
	printf("대출/반납할 책 번호를 입력해주세요 : ");
	scanf_s("%d", &temp_book_num);
	printf("대출할 책 이름을 입력해주세요 : ");
	scanf_s(" %[^\n]s", temp_book_name, (int)sizeof(temp_book_name));
	printf("%s", temp_book_name);
	int turn = 0;
	for (int i = 0; i < 100; i++)
	{
		if (temp_book_num == lib[i].book_num && lib[i].state == 1) // 사용자가 입력한 책 번호가 라이브러리에 있는지, 책을 빌리는중인지
		{
			book_return(i, temp_student_num, temp_book_num, temp_book_name);
			turn++;
		}
	}
	if (turn == 0)
	{
		book_borrow(temp_student_num, temp_book_num, temp_book_name);
	}
	goto start;
}

void book_borrow(int student_num, int book_num, char book_name[100])
{
	for (int i = 0; i < 100; i++)
	{
		if (lib[i].state == 2)
		{
			lib[i].student_num = student_num;
			lib[i].book_num = book_num;
			strcpy_s(lib[i].book_name, 100, book_name);
			lib[i].state = 1;
			printf("%d님이 %s을/를 빌렸습니다", lib[i].student_num, lib[i].book_name);
		}
	}
	WaitKeyInput();
}

void book_return(int num, int student_num, int book_num, char book_name[100])
{
	lib[num].state = 2;
	printf("%d님이 %s을/를 반납했습니다", lib[num].student_num, lib[num].book_name);
	WaitKeyInput();
}

void WaitKeyInput()
{
	while (1)
	{
		if (_kbhit())
		{
			break;
		}
	}
}
