#include <stdio.h>

int main_loop()
{
//for (����; ����; ����) {	}  //������ ������ ��� ����
	for (int a = 1; a <= 10; a++)
	{
		printf("Hello World %d\n", a);
	}
	printf("\n");
	
//while (����) {	} //���� ���ǿ� ���������� ����
	int b = 1;
	while (b <= 10)
	{
		printf("Hello World %d\n", b++);
	}
	printf("\n");

//do {	} while (����);
	int c = 1;
	do 
	{
		printf("Hello World %d\n", c++);
	}
	while (c <= 10);
	printf("\n");

//2�� �ݺ���
	for (int d = 1; d <= 3; d++)
	{
		printf("ù ��° �ݺ��� : %d\n", d);

		for (int e = 1; e <= 5; e++)
		{
			printf("	�� ��° �ݺ��� : %d\n", e);
		}
	}
	printf("\n");

//������
	for (int f = 2; f <= 9; f++)
	{
		printf("%d�� ���\n", f);
		for (int g = 1; g <= 9; g++)
		{
			printf("   %d x %d = %d\n", f, g, f * g);
		}
	}
	printf("\n");

//��
	for (int h = 0; h < 5; h++)
	{
		for (int i = 0; i <= h; i++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n");

//�ݴ� ��
	for (int j = 0; j < 5; j++)
	{
		for (int k = j; k < 5 - 1; k++)
		{
			printf(" ");
		}
		for (int l = 0; l <= j; l++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n");

//�Ƕ�̵带 �׾ƶ� - ������Ʈ
	int floor;
	printf("�� ������ �װڴ���? : ");
	scanf_s("%d", &floor);
	for (int m = 0; m < floor; m++)
	{
		for (int n = m; n < floor - 1; n++)
		{
			printf(" ");
		}
		for (int o = 0; o < m * 2 + 1; o++)
		{
			printf("*");
		}
		printf("\n");
	}



	return 0;
}