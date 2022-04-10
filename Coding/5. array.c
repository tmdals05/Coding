#include <stdio.h>

int main_array()
{
	//배열
	int subway_1 = 30; //지하철 1호차에 30명이 타고 있다
	int subway_2 = 40;
	int subway_3 = 50;

	printf("지하철 1호차에 %d명이 타고 있습니다\n", subway_1);
	printf("지하철 2호차에 %d명이 타고 있습니다\n", subway_2);
	printf("지하철 3호차에 %d명이 타고 있습니다\n", subway_3);
	printf("\n");

	//여러 개의 변수를 함께, 동시에 생성
	int subway_array[3];
	subway_array[0] = 30;
	subway_array[1] = 40;
	subway_array[2] = 50;

	for (int i = 0; i < 3; i++)
	{
		printf("지하철 %d호차에 %d명이 타고 있습니다\n", i + 1, subway_array[i]);
	}
	printf("\n");

	//값 설정 방법
	int a[10] = { 1, 2 ,3 ,4 ,5 ,6 ,7, 8,  9 ,10 };

	for (int n = 0; n < 10; n++)
	{
		printf("%d\n", a[n]);
	}
	printf("\n");

	/*
	배열 크기는 항상 상수로 선언해야함
	int size = 10;
	int arr[size];
	*/

	int b[10] = { 1, 2 }; // 값을 적지 않으면 자동으로 0으로 초기화됨
	for (int m = 0; m < 10; m++)
	{
		printf("%d\n", b[m]);
	}
	printf("\n");

	//배열 크기를 적지않으면 중괄호안의 개수를 세어 자동으로 맞춰줌
	int c[] = { 1, 2 }; // int c[2]

	// 문자열 끝에는 '끝'을 의미하는 NULL 문자 '\0'이 포함되어야 함
	// char str[6] = "coding": // [c][o][d][i][n][g][\0]
	char e[7] = "coding";
	printf("%s\n", e);
	printf("\n");


	char d[] = "coding";
	printf("%s\n", d);
	printf("%zd\n", sizeof(d)); // 자동으로 [\0]이 포함됨
	printf("\n");

	for (int i = 0; i < sizeof(d); i++)
	{
		printf("%c\n", d[i]);
	}

	// 영어 1글자 : 1byte 
	// 한글 1글자 : 2byte
	char kor[] = "배승민"; // 2(배) + 2(승) + 2(민) + 1(\0) = 7 byte
	printf("%s\n", kor);
	printf("%zd\n", sizeof(kor)); // c언어 문법을 엄격하게 지키려면 sizeof를 출력할때는 %d대신 %zd를 사용한다
	printf("\n");

	//char의 크기 : 1 byte
	char c_array[7] = { 'c' ,'o' ,'d' ,'i' ,'n' ,'g', '\0'};
	printf("%s\n", c_array);
	printf("\n");

	
	char c_array1[10] = { 'c' ,'o' ,'d' ,'i' ,'n' ,'g' }; // 선언을 했지만 남는 부분은 자동으로 (\0)이 들어간다
	printf("%s\n", c_array1);
	for (int i = 0; i < sizeof(c_array1); i++)
	{
		printf("%c\n", c_array1[i]);
	}
	printf("\n");

	
	for (int i = 0; i < sizeof(c_array1); i++)
	{
		printf("%d\n", c_array1[i]); //아스키(ASCII) 코드 값 출력 (null 문자 0으로 출력됨)
	}
	printf("\n");

	// 문자열 입력받기
	char name[256];
	printf("이름이 뭐예요? : ");
	scanf_s("%s", name, sizeof(name));
	printf("%s\n", name);
	printf("\n");

	// 아스키(ASCII) 코드란?
	// ANSI (미국표준협회)에서 제시한 표준 코드 체계
	// 7 bit, 총 128개의 코드(0 ~ 127)
	//
	// ex)
	// a : 97 (문자 a의 아스키코드 정수값)
	// A : 65
	// 0 : 48

	printf("문자 : %c\n", 'a');
	printf("아스키코드 : %d\n", 'a'); // 97
	printf("\n");

	printf("문자 : %c\n", 'b');
	printf("아스키코드 : %d\n", 'b'); // 98
	printf("\n");
	
	printf("문자 : %c\n", 'A');
	printf("아스키코드 : %d\n", 'A'); // 65
	printf("\n");

	printf("문자 : %c\n", '\0');
	printf("아스키코드 : %d\n", '\0'); // 0
	printf("\n");
	
	printf("문자 : %c\n", '0');
	printf("아스키코드 : %d\n", '0'); // 48
	printf("\n");
	
	printf("문자 : %c\n", '1');
	printf("아스키코드 : %d\n", '1'); // 49
	printf("\n\n\n");

	// 0 ~ 127 사이의 아스키코드 정수값에 해당하는 문자 확인

	for (int i = 0; i < 128; i++)
	{
		printf("아스키코드 정수 %d : %c\n", i, i);
	}
	
	return 0;
}