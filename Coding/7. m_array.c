#include <stdio.h>

int main_m_array()
{
	//������ �迭 multidimens array
	
	//int i; // ��

	//int arr[5];
	// ������

	// [0][1][2][3][4]

	//int arr2[2][5];
	// ������
	// ������

	// [0][0] [0][1] [0][2] [0][3] [0][4]
	// [1][0] [1][1] [1][2] [1][3] [1][4]

	//int arr3[4][2];
	// ���
	// ���
	// ���
	// ���

	// [0][0] [0][1]
	// [1][0] [1][1]
	// [2][0] [2][1]
	// [3][0] [3][1]


	//int arr4[3][3][3];
	// ����
	// ����
	// ����

	// ����
	// ����
	// ����

	// ����
	// ����
	// ����

	// [0][0][0] [0][0][1] [0][0][2]
	// [0][1][0] [0][1][1] [0][1][2]
	// [0][2][0] [0][2][1] [0][2][2]

	// [1][0][0] [1][0][1] [0][0][2]
	// [1][1][0] [1][1][1] [0][1][2]
	// [1][2][0] [1][2][1] [0][2][2]

	// [2][0][0] [2][0][1] [0][0][2]
	// [2][1][0] [2][1][1] [0][1][2]
	// [2][2][0] [2][2][1] [0][2][2]

	int arr[5] = { 1, 2, 3, 4,5 };
	
	int arr_2[2][5] = { 
		{ 1, 2, 3, 4, 5 },
		{ 6, 7, 8, 9, 10 } 
	};
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("2�����迭 (%d, %d)�� �� : %d\n", i, j, arr_2[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------------\n\n");
	
	int arr_3[4][2] = { 
		{ 1, 2 },
		{ 3, 4 },
		{ 5, 6 },
		{ 7, 8 } 
	};

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("2�����迭 (%d, %d)�� �� : %d\n", i, j, arr_3[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------------\n\n");

	int arr_4[3][3][3] = {
		{
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9}
		},
		{
			{10, 11, 12},
			{13, 14, 15},
			{16, 17, 18}
		},
		{
			{19, 20, 21},
			{22, 23, 24},
			{25, 26, 27}
		},
	};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				printf("3�����迭 (%d, %d, %d)�� �� : %d\n", i, j, k, arr_4[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}

		
	return 0;
}