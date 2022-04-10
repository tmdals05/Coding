#include <stdio.h>

int main_loop()
{
//for (선언; 조건; 증감) {	}  //조건이 맞을시 계속 실행
	for (int a = 1; a <= 10; a++)
	{
		printf("Hello World %d\n", a);
	}
	printf("\n");
	
//while (조건) {	} //값이 조건에 맞을때까지 실행
	int b = 1;
	while (b <= 10)
	{
		printf("Hello World %d\n", b++);
	}
	printf("\n");

//do {	} while (조건);
	int c = 1;
	do 
	{
		printf("Hello World %d\n", c++);
	}
	while (c <= 10);
	printf("\n");

//2중 반복문
	for (int d = 1; d <= 3; d++)
	{
		printf("첫 번째 반복문 : %d\n", d);

		for (int e = 1; e <= 5; e++)
		{
			printf("	두 번째 반복문 : %d\n", e);
		}
	}
	printf("\n");

//구구단
	for (int f = 2; f <= 9; f++)
	{
		printf("%d단 계산\n", f);
		for (int g = 1; g <= 9; g++)
		{
			printf("   %d x %d = %d\n", f, g, f * g);
		}
	}
	printf("\n");

//별
	for (int h = 0; h < 5; h++)
	{
		for (int i = 0; i <= h; i++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n");

//반대 별
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

//피라미드를 쌓아라 - 프로젝트
	int floor;
	printf("몇 층으로 쌓겠느냐? : ");
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