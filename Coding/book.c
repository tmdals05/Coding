#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#define MAX 100

struct library
{
	int book_num; // 책 번호
	char student_name[100]; // 빌리는 학생 이름
	char book_title[100]; // 빌리는 책 제목
	int state; // 0:아무것도 없음, 1:빌리는중, 2:반납
};
struct library lib[MAX];

void book_borrow(char student_name[MAX], int book_num, char book_name[MAX]); // 책 빌리기 함수
void book_return(int num, char student_name[MAX]); // 책 반납하기 함수
void WaitKeyInput(); // 키보드 입력대기 함수

int book_manage()
{
	for (int i = 0; i < 100; i++) // 모든 lib.state를 2로 초기화
	{
		lib[i].state = 0;
	}
	while (1)
	{
		system("cls"); // 화면 초기화
		char temp_student_name[MAX]; // 사용자가 입력한 학생 이름
		int temp_book_num; // 사용자가 입력한 책 번호
		char temp_book_title[MAX]; // 사용자가 입력한 책 제목
		printf("===========책 대출/반납===========\n\n");
		printf("대출/반납할 사람의 이름을 입력해주세요 (나가려면 0입력) : "); // 대출할 사람이름 입력
		scanf_s("%s", temp_student_name, (int)sizeof(temp_student_name));
		if (temp_student_name[0] == '0') // 0입력시 나가기
		{
			return 0;
		}
		printf("대출/반납할 책 번호를 입력해주세요 : "); // 대출할 책 번호 입력
		scanf_s("%d", &temp_book_num);
		int IsRun = 0;
		for (int i = 0; i < MAX; i++)
		{
			if (lib[i].book_num == temp_book_num && lib[i].state == 1) // 사용자가 입력한 책 이름이 lib구조체에 있는지 확인
			{														   // 있다면 책이 빌리는중인지 확인
				book_return(i, temp_student_name); // 책 반납하기 함수
				IsRun++;
				break;
			}
		}
		if (IsRun == 0) // 위 반복문이 실행이 안됐으면 실행
		{
			printf("대출할 책 이름을 입력해주세요 : "); // 대출할 책 이름 입력
			scanf_s(" %[^\n]s", temp_book_title, (int)sizeof(temp_book_title));
			book_borrow(temp_student_name, temp_book_num, temp_book_title); // 책 빌리기 함수
		}
	}
}

void book_borrow(char student_name[MAX], int book_num, char book_name[MAX]) // 책 빌리기 함수
{
	for (int i = 0; i < MAX; i++)
	{
		if (lib[i].state == 2 || lib[i].state == 0) // 해당하는 lib.state가 아무것도 없는 상태(0)이거나
		{											// 빌리는 중(2) 이면 실행
			strcpy_s(lib[i].student_name, sizeof(lib[i].student_name), student_name); // 사용자가 입력한 이름을 lib.student.name에 넣기
			lib[i].book_num = book_num; // 사용자가 입력한 책 번호를 lib.book_num에 넣기
			strcpy_s(lib[i].book_title, sizeof(lib[i].book_title), book_name); // 사용자가 입력한 책 제목을 lib.book_title에 넣기
			lib[i].state = 1; // 해당하는 책을 빌리는 중(1)으로 변경
			printf("\n%s님이 %s을/를 빌렸습니다", lib[i].student_name, lib[i].book_title);
			break;
		}
	}
	WaitKeyInput(); // 키 입력 대기
}

void book_return(int num, char student_name[MAX]) // 책 반납하기 함수
{
	lib[num].state = 2; // 해당하는 책 state를 반납(2)으로 변경
	printf("\n%s님이 %s을/를 반납했습니다", lib[num].student_name, lib[num].book_title);
	WaitKeyInput(); //  키 입력 대기
}

void WaitKeyInput() // 키보드 입력 대기
{
	printf("\n계속하려면 아무키나 누르세요...");
	while (1)
	{
		if (_kbhit()) // 키보드가 입력되면 break
		{
			break;
		}
	}
}
