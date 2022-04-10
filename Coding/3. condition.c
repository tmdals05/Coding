#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main_condition()
{
//if (조건) {...} else {...}
	int a = 15;
	if (a >= 20) //조건이 맞으면 실행
	{
		printf("일반인 입니다\n");
	}
	else //위 조건이 맞지 않으면 실행
	{
		printf("학생입니다\n");
	}
	printf("\n");

//if / else if / else
	int b = 45;
	if (b >= 8 && b <= 13) //조건이 맞으면 실행
	{
		printf("초등학생입니다\n");
	}
	else if (b >= 14 && b <= 16) //위 조건이 맞지 않으면 실행
	{
		printf("중학생입니다\n");
	}
	else if (b >= 17 && b <= 19) //바로 위 조건도 맞지 않으면 실행
	{
		printf("고등학생입니다\n");
	}
	else //위 모든 조건이 맞지 않으면 실행
	{
		printf("학생이 아닌가봐요\n");
	}
	printf("\n");

//break 반복문 탈출
	for (int c = 1; c <= 30; c++)
	{
		if (c >= 6)
		{
			printf("나머지 학생은 집에 가세요\n");
			break;
		}
		printf("%d번 학생은 조별 발표 준비를 하세요\n", c);
	}
	printf("\n");

//continue 실행시 다음 명령을 수행하지않고 위에서 시작
	for (int d = 1; d <= 30; d++)
	{
		if (d >= 6 && d <= 10)
		{
			if (d == 7)
			{
				printf("%d번 학생은 결석입니다\n", d);
				continue;
			}
			printf("%d번 학생은 조별 발표 준비를 하세요\n", d);
		}
	}
	printf("\n");

//&& 그리고
	int e = 10;
	int f = 10;
	int g = 12;
	int h = 12;
	if (e == f && g == h)
	{
		printf("e와 f는 같고, g와 h도 같습니다\n");
	}
	else
	{
		printf("값이 서로 다르네요\n");
	}
	printf("\n");
// || 또는
	int i = 10;
	int j = 10;
	int k = 12;
	int l = 13;
	if (i == j || k == l)
	{
		printf("i와 j혹은 k와 l의 값이 같습니다\n");
	}
	else
	{
		printf("값이 서로 다르네요\n");
	}
	printf("\n");

//가위바위보
	srand(time(NULL));
	int m = rand() % 3;
	if (m == 0)
	{
		printf("가위\n");
	}
	else if (m == 1)
	{
		printf("바위\n");
	}
	else if (m == 2)
	{
		printf("보\n");
	}
	else
	{
		printf("몰라요\n");
	}
	printf("\n");

//switch case
	srand(time(NULL));
	int n = rand() % 3;
	switch (n)
	{
	case 0:printf("가위\n"); break; //break를 사용하지않으면 실행이 되었을때 그 밑에있는 조건은 확인하지않고 바로 실행함
	case 1:printf("바위\n"); break;
	case 2:printf("보\n"); break;
	default:printf("몰라요\n"); break;
	}
	printf("\n");

	int o = 17;
	switch (o)
	{
	case 8:
	case 9:
	case 10:                                 //case뒤에 아무것도 적지 않아도 아무것도 없는것이 실행이 되고 뒤에 break도
	case 11:                                 //없기때문에 break가 나올때까지 밑에있는 case도 계속 실행이 되므로 같은 명령을
	case 12:                                 //반복적으로 넣을때는 마지막에만 명령을쓰고 break를 적으면 된다 
	case 13:printf("초등학생입니다\n"); break; 
	case 14:
	case 15:
	case 16:printf("중학생입니다\n"); break;
	case 17:
	case 18:
	case 19:printf("고등학생입니다\n"); break;
	default : printf("학생이 아닌가봐요\n"); break;
	}
	printf("\n");

//Up and Down
	srand(time(NULL));
	int num = rand() % 100 + 1;
	printf("숫자 : %d\n", num);
	int answer = 0; //정답
	int chance = 5; //기회
	while (1) // 1 : 참, 0 : 거짓
	{
		printf("남은 기회 %d 번\n", chance--);
		printf("숫자를 맞혀보세요 (1~100) : ");
		scanf_s("%d", &answer);
		
		if (answer > num)
		{
			printf("DOWN ↓\n\n");
		}
		else if (answer < num)
		{
			printf("UP ↑\n\n");
		}
		else if (answer == num)
		{
			printf("정답입니다!\n\n");
			break;
		}
		else
		{
			printf("알 수 없는 오류가 발생했습니다\n\n");
		}

		if (chance == 0)
		{
			printf("모든 기회를 다 사용하셨네요, 아쉽게 실패했습니다\n");
			break;
		}
	}

	return 0;
}
