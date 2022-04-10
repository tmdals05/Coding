#include <stdio.h>

//����
void p(int a);

//�Լ� ����
void function_without_return(); //��ȯ���� ���� �Լ�
int function_with_return(); //��ȯ���� �ִ� �Լ�

void function_without_params(); //�Ķ����(���ް�)�� ���� �Լ�
void function_with_params(int num1, int num2, int num3); //�Ķ����(���ް�)�� �ִ� �Լ�

//���
int apple(int total, int ate); //��ü(total)���� ate���� �԰� ���� ���� ��ȯ

//���� �Լ�
int add(int num1, int num2); //���ϱ�
int sub(int num1, int num2); //����
int mul(int num1, int num2); //���ϱ�
int div(int num1, int num2); //������

int main_function()
{
//����
	int a = 2;
	//printf("num�� %d�Դϴ�\n", a); // 2
	p(a);

	// 2 + 3��?
	a = a + 3; // num +=. 3;
	//printf("num�� %d�Դϴ�\n", a); // 5
	p(a);

	// 5 - 1��?
	a -= 1; // num = num -1
	//printf("num�� %d�Դϴ�\n", a); //4
	p(a);

	// 4 * 3��?
	a *= 3;
	//printf("num�� %d�Դϴ�\n", a); //12
	p(a);

	// 12 / 6��?
	a /= 6;
	//printf("num�� %d�Դϴ�\n", a); //2
	p(a);

	printf("\n");

//�Լ� ����
	//��ȯ���� ���� �Լ�
	function_without_return();
	printf("\n");

	//��ȯ���� �ִ� �Լ�
	int ret = function_with_return();
	p(ret);
	printf("\n");

	//�Ķ����(���ް�)�� ���� �Լ�
	function_without_params();
	printf("\n");

	//�Ķ����(���ް�)�� ���� �Լ�
	function_with_params(35, 27, 12);
	printf("\n");

	//�Ķ����(���ް�)�� �ް�, ��ȯ���� �ִ� �Լ�
	int retu = apple(5, 2); //5���� ����� 2���� ����
	printf("��� 5�� �߿� 2���� ������? %d���� ���ƿ�\n", retu);
	printf("\n");
	printf("��� %d�� �߿��� %d���� ������? %d���� ���ƿ�\n", 10, 4, apple(10, 4));
	printf("\n");

//���� �Լ�
	int num = 2;
	num = add(num, 3);
	p(num);

	num = sub(num, 1);
	p(num);
	
	num = mul(num, 3);
	p(num);

	num = div(num, 6);
	p(num);

	return 0;
}

// ����
void p(int a)
{
	printf("num�� %d�Դϴ�\n", a);
}

void function_without_return()
{
	printf("��ȯ���� ���� �Լ��Դϴ�\n");
}

int function_with_return()
{
	printf("��ȯ���� �ִ� �Լ��Դϴ�\n");
	return 10;
}

void function_without_params()
{
	printf("���ް��� ���� �Լ��Դϴ�\n");
}

void function_with_params(int num1, int num2, int num3)
{
	printf("���ް��� �ִ� �Լ��̸�, ���޹��� ���� %d, %d, %d�Դϴ�\n", num1,num2, num3);
}

int apple(int total, int ate)
{
	printf("���ް��� ��ȯ���� �ִ� �Լ��Դϴ�\n");
	return total - ate;
}

int add(int num1, int num2)
{
	return num1 + num2;
}

int sub(int num1, int num2)
{
	return num1 - num2;
}

int mul (int num1, int num2)
{
	return num1 * num2;
}

int div(int num1, int num2)
{
	return num1 / num2;
}