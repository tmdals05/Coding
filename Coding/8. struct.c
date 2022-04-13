#include <stdio.h>

//구조체 선언
struct GameInfo
{
	char* name;
	int year;
	int price;
	char* company;
};

int main()
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

	return 0;
}