#include <stdio.h>

//����ü ����
struct GameInfo
{
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // ���� ��ü ����
};

typedef struct
{
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // ���� ��ü ����
} GAME_INFO;

int main_struct()
{
	//// [���� ���]
	//// �̸� : ��մ°���
	//// �߸ų⵵ : 2022��
	//// ���� 5000��
	//// ���ۻ� : ������۴�

	//char* name = "��մ°���";
	//int year = 2022;
	//int price = 5000;
	//char* company = "������۴�";

	//// [���� ���]
	//// �̸� : ��̾��°���
	//// �߸ų⵵ : 2022��
	//// ���� 10000��
	//// ���ۻ� : ������۴�

	//char* name2 = "��̾��°���";
	//int year = 2022;
	//int price = 10000;
	//char* company2 = "������۴�";


// ����ü ���
	struct GameInfo gameInfo1;
	// struct GameInfo gameInfo2;
	gameInfo1.name = "��մ°���";
	gameInfo1.year = 2022;
	gameInfo1.price = 5000;
	gameInfo1.company = "������۴�";

	// ����ü ���
	printf("   --���� ��� ����--\n");
	printf("  ���Ӹ�   : %s\n", gameInfo1.name);
	printf("  �߸ų⵵ : %d\n", gameInfo1.year);
	printf("  ����     : %d\n", gameInfo1.price);
	printf("  ���ۻ�   : %s\n", gameInfo1.company);
	printf("\n");

	// ����ü�� �迭ó�� �ʱ�ȭ
	struct GameInfo gameInfo2 = {"��̾��°���", 2022, 10000, "������۴�"};
	printf("   --�Ǵٸ� ���� ��� ����--\n");
	printf("  ���Ӹ�   : %s\n", gameInfo2.name);
	printf("  �߸ų⵵ : %d\n", gameInfo2.year);
	printf("  ����     : %d\n", gameInfo2.price);
	printf("  ���ۻ�   : %s\n", gameInfo2.company);
	printf("\n");

	// ����ü �迭
	struct GameInfo gameArray[2] = {
		{"��մ°���", 2022, 5000, "������۴�"},
		{"��̾��°���", 2022, 10000, "������۴�"}
	};

	// ����ü ������
	struct GameInfo* gamePtr; // �̼Ǹ�
	gamePtr = &gameInfo1;
	printf("   --�̼Ǹ��� ���� ��� ����--\n");
	printf("  ���Ӹ�   : %s\n", (*gamePtr).name);
	printf("  �߸ų⵵ : %d\n", (*gamePtr).year);
	printf("  ����     : %d\n", (*gamePtr).price);
	printf("  ���ۻ�   : %s\n", (*gamePtr).company); // ������
	printf("\n");

	printf("  ���Ӹ�   : %s\n", gamePtr->name); // �����ʹ� ->�ε� ��� ����
	printf("  �߸ų⵵ : %d\n", gamePtr->year);
	printf("  ����     : %d\n", gamePtr->price);
	printf("  ���ۻ�   : %s\n", gamePtr->company);
	printf("\n");

	// ���� ��ü ���� �Ұ�;
	gameInfo1.friendGame = &gameInfo2;
	printf("   --���� ��ü�� ���� ��� ����--\n");
	printf("  ���Ӹ�   : %s\n", gameInfo1.friendGame->name);
	printf("  �߸ų⵵ : %d\n", gameInfo1.friendGame->year);
	printf("  ����     : %d\n", gameInfo1.friendGame->price);
	printf("  ���ۻ�   : %s\n", gameInfo1.friendGame->company);
	printf("\n");

// typedef
	// �ڷ����� ���� ����
	int i = 1;
	typedef int ����;
	typedef float �Ǽ�;
	���� �������� = 3; // int i = 3
	�Ǽ� �Ǽ����� = 3.23f; // float f = 3.23f
	printf("�������� : %d, �Ǽ����� %.2f\n\n", ��������, �Ǽ�����);

	typedef struct GameInfo ��������;
	�������� game1;
	game1.name = "�ѱ� ����";
	game1.year = 2015;

	GAME_INFO game2;
	game2.name = "�ѱ� ����2";
	game2.year = 2014;

	//struct GameInformation game3;
	//game3.name = "�ѱ� ����3";



	return 0;
}