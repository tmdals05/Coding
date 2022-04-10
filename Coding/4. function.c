#include <stdio.h>

//선언
void p(int a);

//함수 종류
void function_without_return(); //반환값이 없는 함수
int function_with_return(); //반환값이 있는 함수

void function_without_params(); //파라미터(전달값)가 없는 함수
void function_with_params(int num1, int num2, int num3); //파라미터(전달값)가 있는 함수

//사과
int apple(int total, int ate); //전체(total)에서 ate개를 먹고 남은 수를 반환

//계산기 함수
int add(int num1, int num2); //더하기
int sub(int num1, int num2); //빼기
int mul(int num1, int num2); //곱하기
int div(int num1, int num2); //나누기

int main_function()
{
//계산기
	int a = 2;
	//printf("num은 %d입니다\n", a); // 2
	p(a);

	// 2 + 3은?
	a = a + 3; // num +=. 3;
	//printf("num은 %d입니다\n", a); // 5
	p(a);

	// 5 - 1은?
	a -= 1; // num = num -1
	//printf("num은 %d입니다\n", a); //4
	p(a);

	// 4 * 3은?
	a *= 3;
	//printf("num은 %d입니다\n", a); //12
	p(a);

	// 12 / 6은?
	a /= 6;
	//printf("num은 %d입니다\n", a); //2
	p(a);

	printf("\n");

//함수 종류
	//반환값이 없는 함수
	function_without_return();
	printf("\n");

	//반환값이 있는 함수
	int ret = function_with_return();
	p(ret);
	printf("\n");

	//파라미터(전달값)가 없는 함수
	function_without_params();
	printf("\n");

	//파라미터(전달값)가 없는 함수
	function_with_params(35, 27, 12);
	printf("\n");

	//파라미터(전달값)도 받고, 반환값도 있는 함수
	int retu = apple(5, 2); //5개의 사과중 2개를 먹음
	printf("사과 5개 중에 2개를 먹으면? %d개가 남아요\n", retu);
	printf("\n");
	printf("사과 %d개 중에서 %d개를 먹으면? %d개가 남아요\n", 10, 4, apple(10, 4));
	printf("\n");

//계산기 함수
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

// 정의
void p(int a)
{
	printf("num은 %d입니다\n", a);
}

void function_without_return()
{
	printf("반환값이 없는 함수입니다\n");
}

int function_with_return()
{
	printf("반환값이 있는 함수입니다\n");
	return 10;
}

void function_without_params()
{
	printf("전달값이 없는 함수입니다\n");
}

void function_with_params(int num1, int num2, int num3)
{
	printf("전달값이 있는 함수이며, 전달받은 값은 %d, %d, %d입니다\n", num1,num2, num3);
}

int apple(int total, int ate)
{
	printf("전달값과 변환값이 있는 함수입니다\n");
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