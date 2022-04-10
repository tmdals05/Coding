#include <stdio.h>

int main_array()
{
	//�迭
	int subway_1 = 30; //����ö 1ȣ���� 30���� Ÿ�� �ִ�
	int subway_2 = 40;
	int subway_3 = 50;

	printf("����ö 1ȣ���� %d���� Ÿ�� �ֽ��ϴ�\n", subway_1);
	printf("����ö 2ȣ���� %d���� Ÿ�� �ֽ��ϴ�\n", subway_2);
	printf("����ö 3ȣ���� %d���� Ÿ�� �ֽ��ϴ�\n", subway_3);
	printf("\n");

	//���� ���� ������ �Բ�, ���ÿ� ����
	int subway_array[3];
	subway_array[0] = 30;
	subway_array[1] = 40;
	subway_array[2] = 50;

	for (int i = 0; i < 3; i++)
	{
		printf("����ö %dȣ���� %d���� Ÿ�� �ֽ��ϴ�\n", i + 1, subway_array[i]);
	}
	printf("\n");

	//�� ���� ���
	int a[10] = { 1, 2 ,3 ,4 ,5 ,6 ,7, 8,  9 ,10 };

	for (int n = 0; n < 10; n++)
	{
		printf("%d\n", a[n]);
	}
	printf("\n");

	/*
	�迭 ũ��� �׻� ����� �����ؾ���
	int size = 10;
	int arr[size];
	*/

	int b[10] = { 1, 2 }; // ���� ���� ������ �ڵ����� 0���� �ʱ�ȭ��
	for (int m = 0; m < 10; m++)
	{
		printf("%d\n", b[m]);
	}
	printf("\n");

	//�迭 ũ�⸦ ���������� �߰�ȣ���� ������ ���� �ڵ����� ������
	int c[] = { 1, 2 }; // int c[2]

	// ���ڿ� ������ '��'�� �ǹ��ϴ� NULL ���� '\0'�� ���ԵǾ�� ��
	// char str[6] = "coding": // [c][o][d][i][n][g][\0]
	char e[7] = "coding";
	printf("%s\n", e);
	printf("\n");


	char d[] = "coding";
	printf("%s\n", d);
	printf("%zd\n", sizeof(d)); // �ڵ����� [\0]�� ���Ե�
	printf("\n");

	for (int i = 0; i < sizeof(d); i++)
	{
		printf("%c\n", d[i]);
	}

	// ���� 1���� : 1byte 
	// �ѱ� 1���� : 2byte
	char kor[] = "��¹�"; // 2(��) + 2(��) + 2(��) + 1(\0) = 7 byte
	printf("%s\n", kor);
	printf("%zd\n", sizeof(kor)); // c��� ������ �����ϰ� ��Ű���� sizeof�� ����Ҷ��� %d��� %zd�� ����Ѵ�
	printf("\n");

	//char�� ũ�� : 1 byte
	char c_array[7] = { 'c' ,'o' ,'d' ,'i' ,'n' ,'g', '\0'};
	printf("%s\n", c_array);
	printf("\n");

	
	char c_array1[10] = { 'c' ,'o' ,'d' ,'i' ,'n' ,'g' }; // ������ ������ ���� �κ��� �ڵ����� (\0)�� ����
	printf("%s\n", c_array1);
	for (int i = 0; i < sizeof(c_array1); i++)
	{
		printf("%c\n", c_array1[i]);
	}
	printf("\n");

	
	for (int i = 0; i < sizeof(c_array1); i++)
	{
		printf("%d\n", c_array1[i]); //�ƽ�Ű(ASCII) �ڵ� �� ��� (null ���� 0���� ��µ�)
	}
	printf("\n");

	// ���ڿ� �Է¹ޱ�
	char name[256];
	printf("�̸��� ������? : ");
	scanf_s("%s", name, sizeof(name));
	printf("%s\n", name);
	printf("\n");

	// �ƽ�Ű(ASCII) �ڵ��?
	// ANSI (�̱�ǥ����ȸ)���� ������ ǥ�� �ڵ� ü��
	// 7 bit, �� 128���� �ڵ�(0 ~ 127)
	//
	// ex)
	// a : 97 (���� a�� �ƽ�Ű�ڵ� ������)
	// A : 65
	// 0 : 48

	printf("���� : %c\n", 'a');
	printf("�ƽ�Ű�ڵ� : %d\n", 'a'); // 97
	printf("\n");

	printf("���� : %c\n", 'b');
	printf("�ƽ�Ű�ڵ� : %d\n", 'b'); // 98
	printf("\n");
	
	printf("���� : %c\n", 'A');
	printf("�ƽ�Ű�ڵ� : %d\n", 'A'); // 65
	printf("\n");

	printf("���� : %c\n", '\0');
	printf("�ƽ�Ű�ڵ� : %d\n", '\0'); // 0
	printf("\n");
	
	printf("���� : %c\n", '0');
	printf("�ƽ�Ű�ڵ� : %d\n", '0'); // 48
	printf("\n");
	
	printf("���� : %c\n", '1');
	printf("�ƽ�Ű�ڵ� : %d\n", '1'); // 49
	printf("\n\n\n");

	// 0 ~ 127 ������ �ƽ�Ű�ڵ� �������� �ش��ϴ� ���� Ȯ��

	for (int i = 0; i < 128; i++)
	{
		printf("�ƽ�Ű�ڵ� ���� %d : %c\n", i, i);
	}
	
	return 0;
}