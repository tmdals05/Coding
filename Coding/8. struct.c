#include <stdio.h>

//구조체 선언
struct GameInfo
{
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // 연관 업체 게임
};

typedef struct
{
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // 연관 업체 게임
} GAME_INFO;

int main_struct()
{
	//// [게임 출시]
	//// 이름 : 재밌는게임
	//// 발매년도 : 2022년
	//// 가격 5000원
	//// 제작사 : 배꼽컴퍼니

	//char* name = "재밌는게임";
	//int year = 2022;
	//int price = 5000;
	//char* company = "배꼽컴퍼니";

	//// [게임 출시]
	//// 이름 : 재미없는게임
	//// 발매년도 : 2022년
	//// 가격 10000원
	//// 제작사 : 배띵컴퍼니

	//char* name2 = "재미없는게임";
	//int year = 2022;
	//int price = 10000;
	//char* company2 = "배띵컴퍼니";


// 구조체 사용
	struct GameInfo gameInfo1;
	// struct GameInfo gameInfo2;
	gameInfo1.name = "재밌는게임";
	gameInfo1.year = 2022;
	gameInfo1.price = 5000;
	gameInfo1.company = "배꼽컴퍼니";

	// 구조체 출력
	printf("   --게임 출시 정보--\n");
	printf("  게임명   : %s\n", gameInfo1.name);
	printf("  발매년도 : %d\n", gameInfo1.year);
	printf("  가격     : %d\n", gameInfo1.price);
	printf("  제작사   : %s\n", gameInfo1.company);
	printf("\n");

	// 구조체를 배열처럼 초기화
	struct GameInfo gameInfo2 = {"재미없는게임", 2022, 10000, "배띵컴퍼니"};
	printf("   --또다른 게임 출시 정보--\n");
	printf("  게임명   : %s\n", gameInfo2.name);
	printf("  발매년도 : %d\n", gameInfo2.year);
	printf("  가격     : %d\n", gameInfo2.price);
	printf("  제작사   : %s\n", gameInfo2.company);
	printf("\n");

	// 구조체 배열
	struct GameInfo gameArray[2] = {
		{"재밌는게임", 2022, 5000, "배꼽컴퍼니"},
		{"재미없는게임", 2022, 10000, "배띵컴퍼니"}
	};

	// 구조체 포인터
	struct GameInfo* gamePtr; // 미션맨
	gamePtr = &gameInfo1;
	printf("   --미션맨의 게임 출시 정보--\n");
	printf("  게임명   : %s\n", (*gamePtr).name);
	printf("  발매년도 : %d\n", (*gamePtr).year);
	printf("  가격     : %d\n", (*gamePtr).price);
	printf("  제작사   : %s\n", (*gamePtr).company); // 불편함
	printf("\n");

	printf("  게임명   : %s\n", gamePtr->name); // 포인터는 ->로도 사용 가능
	printf("  발매년도 : %d\n", gamePtr->year);
	printf("  가격     : %d\n", gamePtr->price);
	printf("  제작사   : %s\n", gamePtr->company);
	printf("\n");

	// 연관 업체 게임 소개;
	gameInfo1.friendGame = &gameInfo2;
	printf("   --연관 업체의 게임 출시 정보--\n");
	printf("  게임명   : %s\n", gameInfo1.friendGame->name);
	printf("  발매년도 : %d\n", gameInfo1.friendGame->year);
	printf("  가격     : %d\n", gameInfo1.friendGame->price);
	printf("  제작사   : %s\n", gameInfo1.friendGame->company);
	printf("\n");

// typedef
	// 자료형의 별명 지정
	int i = 1;
	typedef int 정수;
	typedef float 실수;
	정수 정수변수 = 3; // int i = 3
	실수 실수변수 = 3.23f; // float f = 3.23f
	printf("정수변수 : %d, 실수변수 %.2f\n\n", 정수변수, 실수변수);

	typedef struct GameInfo 게임정보;
	게임정보 game1;
	game1.name = "한글 게임";
	game1.year = 2015;

	GAME_INFO game2;
	game2.name = "한글 게임2";
	game2.year = 2014;

	//struct GameInformation game3;
	//game3.name = "한글 게임3";



	return 0;
}