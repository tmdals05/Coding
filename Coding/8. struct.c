#include <stdio.h>

//����ü ����
struct GameInfo
{
	char* name;
	int year;
	int price;
	char* company;
};

int main()
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

	return 0;
}