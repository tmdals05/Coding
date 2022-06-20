#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#define MAX 100
#define SIZE 10

//배승민<대출,반납>, 송재겸<회원관리>

void login(); // 로그인 함수
void WaitKeyInput(); // 키보드 입력대기 함수
void book_borrow(char student_name[MAX], int book_num, char book_name[MAX]); // 책 빌리기 함수
void book_return(int num, char student_name[MAX]); // 책 반납하기 함수
void seat();
int book_manage(); // 책 빌리기/반납하기
void CursorView(char tf); // 커서 보이기/없애기

int seatChoice;
int choice_1;
int seats[SIZE] = { 0 }; //모든 값을 0으로 초기화 함.
int login_turn = 0;
char student[MAX][MAX]; // 회원가입한 학생 이름

struct library
{
	int book_num; // 책 번호
	char student_name[MAX]; // 빌리는 학생 이름
	char book_title[MAX]; // 빌리는 책 제목
	int state; // 0:아무것도 없음, 1:빌리는중, 2:반납
};
struct library lib[MAX];

void login()
{
	system("cls"); // 화면 초기화
	char temp_name[MAX]; // 사용자가 입력할 이름
	printf("===========회원정보 관리===========\n");
	printf("회원가입할 이름을 입력해주세요(나가려면 0입력) : ");
	scanf_s("%s", temp_name, (int)sizeof(temp_name));
	if (temp_name[0] == '0') // 0입력시 돌아가기
	{
		return 0;
	}
	int IsRun[2] = { 0 }, choice;
	for (int i = 0; i < MAX; i++)
	{
		if (strcmp(temp_name, lib[i].student_name) == 0 && lib[i].state == 1) // 사용자가 입력한 이름과 lib.student_name에 있는 이름 비교
		{																	  // 빌리는중인지 확인
			printf("%s님이 현재 대출하고 계신 책은 %s입니다.\n", lib[i].student_name, lib[i].book_title);
			IsRun[0]++;
			IsRun[1]++;
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		if (IsRun[1] == 0 && strcmp(temp_name, student[i]) == 0)
		{
			printf("%s님이 현재 대출하고 계신 책은 없습니다.", temp_name);
			IsRun[0]++;
		}
	}
	if (IsRun[0] == 0)
	{
		printf("일치하는 이름이 없어 회원가입을 진행합니다.\n동의하십니까?(동의시 1 입력) : "); // 회원가입 진행
		scanf_s("%d", &choice);
		if (choice == 1)
		{
			strcpy_s(student[login_turn], sizeof(student[login_turn]), temp_name);
			login_turn++;
			printf("회원가입이 되었습니다");
		}
		else
		{
			printf("가입이 취소되었습니다.");
		}
	}
	WaitKeyInput();
}

int book_manage()
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
	int turn = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (strcmp(student[i], temp_student_name) == 0) // 0입력시 돌아가기
		{
			turn++;
		}
	}
	if (turn == 0) // 회원가입이 안되어있으면 실행
	{
		printf("\n");
		printf("회원가입이 되어있지 않은 이름입니다");
		WaitKeyInput();
		return 0;
	}
	printf("\n");
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
		printf("\n");
		printf("대출할 책 이름을 입력해주세요 : "); // 대출할 책 이름 입력
		scanf_s(" %[^\n]s", temp_book_title, (int)sizeof(temp_book_title));
		book_borrow(temp_student_name, temp_book_num, temp_book_title); // 책 빌리기 함수
	}
	return 0;
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

void CursorView(char tf) // 커서 보이기/없애기
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = tf;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
//----------------------------------------------------------------------------
//김근형 프로그램 합치기, 프로그램 수정, 책 위치 찾기 프로그램 만들기, 전체 프로그램 기초 틀 짜기....??
int main()
{
	int number;
	int book_number, book_b;

	int i;
	system("cls"); // 화면 초기화
	printf("<도서대출 프로그램>\n");
	printf("1. 회원정보 관리\n");
	printf("2. 도서 대여 관리\n");
	printf("3. 도서관 자리 예약하기\n");
	printf("4. 도서 위치\n");
	printf("5.종료\n");
	printf("\n:");

	scanf_s("%d", &number);

	for (int i = 0; i < MAX; i++) // 모든 lib.state를 2로 초기화
	{
		lib[i].state = 0;
	}

	while (number != 5)
	{
		switch (number)
		{
		case 1:

			login();
			break;
		case 2:
			book_manage();
			break;
		case 3:
			//이은우<도서관 자리 관리>
			seat();
			break;
		case 4:
			//김근형<도서 위치 찾기>
			number = 0;
			printf("십진 분류:");
			scanf_s("%d", &book_number);
			printf("\n");

			while (book_number != 0)
			{
				switch ((book_number / 100) + 1)
				{
				case 1:
					printf("총류 A구역 입니다\n");
					printf("\n");
					book_number = 0;

					printf("10. 도서학 , 서지학\n");
					printf("20. 문헌정보학\n");
					printf("30. 백과사전\n");
					printf("40. 강연집 , 수필집 , 연설문집\n");
					printf("50. 일반연속간행물\n");
					printf("60. 일반학회 , 단체 , 협회 , 기관\n");
					printf("70. 신문 , 언론 , 저널리즘\n");
					printf("80. 일반전집 , 총서\n");
					printf("90. 향토자료\n");
					printf("이전 : 1000\n");
					printf("종료 : 0\n");
					printf("\n");
					printf(":");

					scanf_s("%d", &book_b);
					if (book_b != 1000)
					{
						switch (book_b)
						{
						case 10:
							printf("\n");
							printf("A-1구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;

						case 20:
							printf("\n");
							printf("A-2구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 30:
							printf("\n");
							printf("A-3구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 40:
							printf("\n");
							printf("A-4구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 50:
							printf("\n");
							printf("A-5구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 60:
							printf("\n");
							printf("A-6구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 70:
							printf("\n");
							printf("A-7구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 80:
							printf("\n");
							printf("A-8구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 90:
							printf("\n");
							printf("A-9구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						default:
							book_b = 0;
							printf("\n");
							printf("잘못된 번호 입니다.\n");
							printf("\n");
							book_number = 10;
							break;

						}
					}
					else if (book_b == 1000)
					{
						printf("\n");
						printf("십진 분류:");
						scanf_s("%d", &book_number);
					}
					break;
				case 2:
					printf("철학 B구역 입니다\n");
					printf("\n");
					book_number = 0;

					printf("110. 형이상학\n");
					printf("120. 인식록 , 인과론 , 인간학\n");
					printf("130. 철학의 체계\n");
					printf("140. 경학\n");
					printf("150. 동양철학 , 사상\n");
					printf("160. 서양철학\n");
					printf("170. 논리학\n");
					printf("180. 심리학\n");
					printf("190. 윤리학 , 도덕철학\n");
					printf("이전 : 1000\n");
					printf("종료 : 0\n");
					printf("\n");
					printf(":");

					scanf_s("%d", &book_b);
					if (book_b != 1000)
					{
						switch (book_b)
						{
						case 110:
							printf("\n");
							printf("B-1구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 120:
							printf("\n");
							printf("B-2구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 130:
							printf("\n");
							printf("B-3구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 140:
							printf("\n");
							printf("B-4구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 150:
							printf("\n");
							printf("B-5구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 160:
							printf("\n");
							printf("B-6구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 170:
							printf("\n");
							printf("B-7구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 180:
							printf("\n");
							printf("B-8구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 190:
							printf("\n");
							printf("B-9구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						default:
							book_b = 0;
							printf("\n");
							printf("잘못된 번호 입니다.\n");
							printf("\n");
							book_number = 100;
							break;
						}
					}
					else if (book_b == 1000)
					{
						printf("\n");
						printf("십진 분류:");
						scanf_s("%d", &book_number);
					}
					break;
				case 3:
					printf("종교 C구역 입니다\n");
					printf("\n");
					book_number = 0;
					printf("210. 비교종교\n");
					printf("220. 불교\n");
					printf("230. 기독교\n");
					printf("240. 도교\n");
					printf("250. 천도교\n");
					printf("260. 신도\n");
					printf("270. 힌두교 , 브라만교\n");
					printf("280. 이슬람교(회교)\n");
					printf("290. 기타 제종교\n");
					printf("이전 : 1000\n");
					printf("종료 : 0\n");
					printf("\n");
					printf(":");

					scanf_s("%d", &book_b);
					if (book_b != 1000)
					{
						switch (book_b)
						{
						case 210:
							printf("\n");
							printf("C-1구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 220:
							printf("\n");
							printf("C-2구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 230:
							printf("\n");
							printf("C-3구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 240:
							printf("\n");
							printf("C-4구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 250:
							printf("\n");
							printf("C-5구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 260:
							printf("\n");
							printf("C-6구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 270:
							printf("\n");
							printf("C-7구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 280:
							printf("\n");
							printf("C-8구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 290:
							printf("\n");
							printf("C-9구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						default:
							book_b = 0;
							printf("\n");
							printf("잘못된 번호 입니다.\n");
							printf("\n");
							book_number = 200;
							break;
						}
					}
					else if (book_b == 1000)
					{
						printf("\n");
						printf("십진 분류:");
						scanf_s("%d", &book_number);
					}
					break;
				case 4:
					printf("사회과학 D구역 입니다\n");
					printf("\n");
					book_number = 0;
					printf("310. 통계학\n");
					printf("320. 경제학\n");
					printf("330. 사회학 , 사회문제\n");
					printf("340. 정치학\n");
					printf("350. 행정학\n");
					printf("360. 법학\n");
					printf("370. 교육학\n");
					printf("380. 풍속 , 예절 , 민속학\n");
					printf("390. 국방 , 군사학\n");
					printf("이전 : 1000\n");
					printf("종료 : 0\n");
					printf("\n");
					printf(":");

					scanf_s("%d", &book_b);
					if (book_b != 1000)
					{
						switch (book_b)
						{
						case 310:
							printf("\n");
							printf("D-1구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 320:
							printf("\n");
							printf("D-2구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 330:
							printf("\n");
							printf("D-3구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 340:
							printf("\n");
							printf("D-4구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 350:
							printf("\n");
							printf("D-5구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 360:
							printf("\n");
							printf("D-6구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 370:
							printf("\n");
							printf("D-7구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 380:
							printf("\n");
							printf("D-8구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 390:
							printf("\n");
							printf("D-9구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						default:
							book_b = 0;
							printf("\n");
							printf("잘못된 번호 입니다.\n");
							printf("\n");
							book_number = 300;
							break;
						}
					}
					else if (book_b == 1000)
					{
						printf("\n");
						printf("십진 분류:");
						scanf_s("%d", &book_number);
					}
					break;
				case 5:
					printf("자연과학 E구역 입니다\n");
					printf("\n");
					book_number = 0;
					printf("410. 수학\n");
					printf("420. 물리학\n");
					printf("430. 화학\n");
					printf("440. 천문학\n");
					printf("450. 지학\n");
					printf("460. 광물학\n");
					printf("470. 생명과학 , 브라만교\n");
					printf("480. 식물학\n");
					printf("490. 동물학\n");
					printf("이전 : 1000\n");
					printf("종료 : 0\n");
					printf("\n");
					printf(":");

					scanf_s("%d", &book_b);
					if (book_b != 1000)
					{
						switch (book_b)
						{
						case 410:
							printf("\n");
							printf("E-1구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 420:
							printf("\n");
							printf("E-2구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 430:
							printf("\n");
							printf("E-3구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 440:
							printf("\n");
							printf("E-4구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 450:
							printf("\n");
							printf("E-5구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 460:
							printf("\n");
							printf("E-6구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 470:
							printf("\n");
							printf("E-7구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 480:
							printf("\n");
							printf("E-8구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 490:
							printf("\n");
							printf("E-9구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						default:
							book_b = 0;
							printf("\n");
							printf("잘못된 번호 입니다.\n");
							printf("\n");
							book_number = 400;
							break;
						}
					}
					else if (book_b == 1000)
					{
						printf("\n");
						printf("십진 분류:");
						scanf_s("%d", &book_number);
					}
					break;
				case 6:
					printf("기술과학 F구역 입니다\n");
					printf("\n");
					book_number = 0;
					printf("510. 의학\n");
					printf("520. 농업 , 농학\n");
					printf("530. 공학 , 공업일반 , 토목공학 , 환경공학\n");
					printf("540. 건축공학\n");
					printf("550. 기계공학\n");
					printf("560. 전기공학 , 전자공학\n");
					printf("570. 화학공학\n");
					printf("580. 제조업\n");
					printf("590. 생명과학\n");
					printf("이전 : 1000\n");
					printf("종료 : 0\n");
					printf("\n");
					printf(":");

					scanf_s("%d", &book_b);
					if (book_b != 1000)
					{
						switch (book_b)
						{
						case 510:
							printf("\n");
							printf("F-1구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 520:
							printf("\n");
							printf("F-2구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 530:
							printf("\n");
							printf("F-3구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 540:
							printf("\n");
							printf("F-4구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 550:
							printf("\n");
							printf("F-5구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 560:
							printf("\n");
							printf("F-6구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 570:
							printf("\n");
							printf("F-7구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 580:
							printf("\n");
							printf("F-8구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 590:
							printf("\n");
							printf("F-9구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						default:
							book_b = 0;
							printf("\n");
							printf("잘못된 번호 입니다.\n");
							printf("\n");
							book_number = 500;
							break;
						}
					}
					else if (book_b == 1000)
					{
						printf("\n");
						printf("십진 분류:");
						scanf_s("%d", &book_number);
					}
					break;
				case 7:
					printf("예술 G구역 입니다\n");
					printf("\n");
					book_number = 0;
					printf("610. 건축물\n");
					printf("620. 조각 , 조형예술\n");
					printf("630. 공예 , 장식미술\n");
					printf("640. 서예\n");
					printf("650. 회화 , 도화\n");
					printf("660. 사진예술\n");
					printf("670. 음악\n");
					printf("680. 공연예술 , 매체예술\n");
					printf("690. 오락 , 스포츠\n");
					printf("이전 : 1000\n");
					printf("종료 : 0\n");
					printf("\n");
					printf(":");

					scanf_s("%d", &book_b);
					if (book_b != 1000)
					{
						switch (book_b)
						{
						case 610:
							printf("\n");
							printf("G-1구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 620:
							printf("\n");
							printf("G-2구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 630:
							printf("\n");
							printf("G-3구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 640:
							printf("\n");
							printf("G-4구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 650:
							printf("\n");
							printf("G-5구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 660:
							printf("\n");
							printf("G-6구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 670:
							printf("\n");
							printf("G-7구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 680:
							printf("\n");
							printf("G-8구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 690:
							printf("\n");
							printf("G-9구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						default:
							book_b = 0;
							printf("\n");
							printf("잘못된 번호 입니다.\n");
							printf("\n");
							book_number = 600;
							break;
						}
					}
					else if (book_b == 1000)
					{
						printf("\n");
						printf("십진 분류:");
						scanf_s("%d", &book_number);
					}
					break;
				case 8:
					printf("언어 H구역 입니다\n");
					printf("\n");
					book_number = 0;
					printf("710. 한국어\n");
					printf("720. 중국어\n");
					printf("730. 일본어 , 기타 아시아 제어\n");
					printf("740. 영어\n");
					printf("750. 독일어\n");
					printf("760. 프랑스어\n");
					printf("770. 스페인어 , 포르투갈어\n");
					printf("780. 이탈리아어\n");
					printf("790. 기타제어\n");
					printf("이전 : 1000\n");
					printf("종료 : 0\n");
					printf("\n");
					printf(":");

					scanf_s("%d", &book_b);
					if (book_b != 1000)
					{
						switch (book_b)
						{
						case 710:
							printf("\n");
							printf("H-1구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 720:
							printf("\n");
							printf("H-2구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 730:
							printf("\n");
							printf("H-3구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 740:
							printf("\n");
							printf("H-4구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 750:
							printf("\n");
							printf("H-5구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 760:
							printf("\n");
							printf("H-6구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 770:
							printf("\n");
							printf("H-7구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 780:
							printf("\n");
							printf("H-8구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 790:
							printf("\n");
							printf("H-9구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						default:
							book_b = 0;
							printf("\n");
							printf("잘못된 번호 입니다.\n");
							printf("\n");
							book_number = 700;
							break;
						}
					}
					else if (book_b == 1000)
					{
						printf("\n");
						printf("십진 분류:");
						scanf_s("%d", &book_number);
					}
					break;
				case 9:
					printf("문학 I구역 입니다\n");
					printf("\n");
					book_number = 0;
					printf("810. 한국문학\n");
					printf("820. 중국문학\n");
					printf("830. 일본문학 , 기타 아시아 문학\n");
					printf("840. 영미문학\n");
					printf("850. 독일문학\n");
					printf("860. 프랑스문학\n");
					printf("870. 스페인 , 포르투갈문학\n");
					printf("880. 이탈리아문학\n");
					printf("890. 기타제문학\n");
					printf("이전 : 1000\n");
					printf("종료 : 0\n");
					printf("\n");
					printf(":");

					scanf_s("%d", &book_b);
					if (book_b != 1000)
					{
						switch (book_b)
						{
						case 810:
							printf("\n");
							printf("I-1구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 820:
							printf("\n");
							printf("I-2구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 830:
							printf("\n");
							printf("I-3구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 840:
							printf("\n");
							printf("I-4구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 850:
							printf("\n");
							printf("I-5구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 860:
							printf("\n");
							printf("I-6구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 870:
							printf("\n");
							printf("I-7구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 880:
							printf("\n");
							printf("I-8구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 890:
							printf("\n");
							printf("I-9구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						default:
							book_b = 0;
							printf("\n");
							printf("잘못된 번호 입니다.\n");
							printf("\n");
							book_number = 800;
							break;
						}
					}
					else if (book_b == 1000)
					{
						printf("\n");
						printf("십진 분류:");
						scanf_s("%d", &book_number);
					}
					break;
				case 10:
					printf("역사 J구역 입니다\n");
					printf("\n");
					book_number = 0;
					printf("910. 아시아\n");
					printf("920. 유럽\n");
					printf("930. 아프리카\n");
					printf("940. 북아메리카\n");
					printf("950. 남아메리카\n");
					printf("960. 오세아니아\n");
					printf("970. 양극지방\n");
					printf("980. 지리\n");
					printf("990. 전기\n");
					printf("이전 : 1000\n");
					printf("종료 : 0\n");
					printf("\n");
					printf(":");

					scanf_s("%d", &book_b);
					if (book_b != 1000)
					{
						switch (book_b)
						{
						case 910:
							printf("\n");
							printf("J-1구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 920:
							printf("\n");
							printf("J-2구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 930:
							printf("\n");
							printf("J-3구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 940:
							printf("\n");
							printf("J-4구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 950:
							printf("\n");
							printf("J-5구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 960:
							printf("\n");
							printf("J-6구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 970:
							printf("\n");
							printf("J-7구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 980:
							printf("\n");
							printf("J-8구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						case 990:
							printf("\n");
							printf("J-9구역\n");
							printf("\n");
							printf("종료 : 0\n");
							printf("십진 분류:");
							scanf_s("%d", &book_number);
							printf("\n");
							break;
						default:
							book_b = 0;
							printf("\n");
							printf("잘못된 번호 입니다.\n");
							printf("\n");
							book_number = 900;
							break;
						}
					}
					else if (book_b == 1000)
					{
						printf("\n");
						printf("십진 분류:");
						scanf_s("%d", &book_number);
					}
					break;
				}

			}

		}
		system("cls");
		printf("\n");
		printf("<도서대출 프로그램>\n");
		printf("1. 회원정보 관리\n");
		printf("2. 도서 대여 관리\n");
		printf("3. 도서위치 안내\n");
		printf("4. 도서관 자리 예약하기\n");
		printf("5.종료\n");
		printf("\n");
		printf(":");
		scanf_s("%d", &number);


	}
	return 0;
}

void seat()
{
	system("cls");
	printf("******좌석 예약 시스템******\n");
	printf("종료 : 0\n");
	printf("\n좌석을 예약하시겠습니까?(1) ");
	scanf_s("%d", &choice_1);

	while (choice_1 == 1)
	{
		printf("\n");
		printf("----------------------\n");
		for (int i = 1; i <= 10; i++)
			printf(" %d", i);
		printf("\n----------------------\n");
		for (int i = 0; i < 10; i++)
			printf(" %d", seats[i]);
		printf("\n몇번째 좌석? ");
		scanf_s("%d", &seatChoice); //좌석 선택
		if (seats[seatChoice - 1] == 0) { // -1인 이유 설명해주기
			printf("\n예약되었습니다.\n");
			printf("\n");
			seats[seatChoice - 1] = 1;
		}
		else
		{
			printf("\n이미 예약된 자리입니다\n");
			printf("\n");
		}
		fflush(stdin); // 이 부분 설명해주기
		printf("----------------------\n");
		for (int i = 1; i <= 10; i++)
			printf(" %d", i);
		printf("\n----------------------\n");
		for (int i = 0; i < 10; i++)
			printf(" %d", seats[i]);
		WaitKeyInput();
		system("cls");
		printf("******좌석 예약 시스템******\n");
		printf("종료 : 0\n");
		printf("\n좌석을 예약하시겠습니까?(1) ");
		scanf_s("%d", &choice_1);
	}
}
