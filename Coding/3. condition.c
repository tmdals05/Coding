#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main_condition()
{
//if (����) {...} else {...}
	int a = 15;
	if (a >= 20) //������ ������ ����
	{
		printf("�Ϲ��� �Դϴ�\n");
	}
	else //�� ������ ���� ������ ����
	{
		printf("�л��Դϴ�\n");
	}
	printf("\n");

//if / else if / else
	int b = 45;
	if (b >= 8 && b <= 13) //������ ������ ����
	{
		printf("�ʵ��л��Դϴ�\n");
	}
	else if (b >= 14 && b <= 16) //�� ������ ���� ������ ����
	{
		printf("���л��Դϴ�\n");
	}
	else if (b >= 17 && b <= 19) //�ٷ� �� ���ǵ� ���� ������ ����
	{
		printf("����л��Դϴ�\n");
	}
	else //�� ��� ������ ���� ������ ����
	{
		printf("�л��� �ƴѰ�����\n");
	}
	printf("\n");

//break �ݺ��� Ż��
	for (int c = 1; c <= 30; c++)
	{
		if (c >= 6)
		{
			printf("������ �л��� ���� ������\n");
			break;
		}
		printf("%d�� �л��� ���� ��ǥ �غ� �ϼ���\n", c);
	}
	printf("\n");

//continue ����� ���� ����� ���������ʰ� ������ ����
	for (int d = 1; d <= 30; d++)
	{
		if (d >= 6 && d <= 10)
		{
			if (d == 7)
			{
				printf("%d�� �л��� �Ἦ�Դϴ�\n", d);
				continue;
			}
			printf("%d�� �л��� ���� ��ǥ �غ� �ϼ���\n", d);
		}
	}
	printf("\n");

//&& �׸���
	int e = 10;
	int f = 10;
	int g = 12;
	int h = 12;
	if (e == f && g == h)
	{
		printf("e�� f�� ����, g�� h�� �����ϴ�\n");
	}
	else
	{
		printf("���� ���� �ٸ��׿�\n");
	}
	printf("\n");
// || �Ǵ�
	int i = 10;
	int j = 10;
	int k = 12;
	int l = 13;
	if (i == j || k == l)
	{
		printf("i�� jȤ�� k�� l�� ���� �����ϴ�\n");
	}
	else
	{
		printf("���� ���� �ٸ��׿�\n");
	}
	printf("\n");

//����������
	srand(time(NULL));
	int m = rand() % 3;
	if (m == 0)
	{
		printf("����\n");
	}
	else if (m == 1)
	{
		printf("����\n");
	}
	else if (m == 2)
	{
		printf("��\n");
	}
	else
	{
		printf("�����\n");
	}
	printf("\n");

//switch case
	srand(time(NULL));
	int n = rand() % 3;
	switch (n)
	{
	case 0:printf("����\n"); break; //break�� ������������� ������ �Ǿ����� �� �ؿ��ִ� ������ Ȯ�������ʰ� �ٷ� ������
	case 1:printf("����\n"); break;
	case 2:printf("��\n"); break;
	default:printf("�����\n"); break;
	}
	printf("\n");

	int o = 17;
	switch (o)
	{
	case 8:
	case 9:
	case 10:                                 //case�ڿ� �ƹ��͵� ���� �ʾƵ� �ƹ��͵� ���°��� ������ �ǰ� �ڿ� break��
	case 11:                                 //���⶧���� break�� ���ö����� �ؿ��ִ� case�� ��� ������ �ǹǷ� ���� �����
	case 12:                                 //�ݺ������� �������� ���������� ��������� break�� ������ �ȴ� 
	case 13:printf("�ʵ��л��Դϴ�\n"); break; 
	case 14:
	case 15:
	case 16:printf("���л��Դϴ�\n"); break;
	case 17:
	case 18:
	case 19:printf("����л��Դϴ�\n"); break;
	default : printf("�л��� �ƴѰ�����\n"); break;
	}
	printf("\n");

//Up and Down
	srand(time(NULL));
	int num = rand() % 100 + 1;
	printf("���� : %d\n", num);
	int answer = 0; //����
	int chance = 5; //��ȸ
	while (1) // 1 : ��, 0 : ����
	{
		printf("���� ��ȸ %d ��\n", chance--);
		printf("���ڸ� ���������� (1~100) : ");
		scanf_s("%d", &answer);
		
		if (answer > num)
		{
			printf("DOWN ��\n\n");
		}
		else if (answer < num)
		{
			printf("UP ��\n\n");
		}
		else if (answer == num)
		{
			printf("�����Դϴ�!\n\n");
			break;
		}
		else
		{
			printf("�� �� ���� ������ �߻��߽��ϴ�\n\n");
		}

		if (chance == 0)
		{
			printf("��� ��ȸ�� �� ����ϼ̳׿�, �ƽ��� �����߽��ϴ�\n");
			break;
		}
	}

	return 0;
}
