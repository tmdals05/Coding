#include <stdio.h>

#define MAX 10000

int main()
{
	// ���� �����
	// ���Ͽ� � �����͸� ����
	// ���Ͽ� ����� �����͸� �ҷ�����

	// fputs, fgets
	char line[MAX];  // char line[10000]
	FILE* file = fopen("F:\\test1.txt", "wb"); // r(�б� ����), w(���� ����), a(�̾��), t(�ؽ�Ʈ), b(���̳ʸ� ������)

	if (file == NULL)
	{
		printf("���� ���� ����\n");
		return 0;
	}
	
	fputs("fputs�� �̿��ؼ� ���� ����Կ�\n", file);
	fputs("�� �������� Ȯ�����ּ���\n", file);

	// ������ ���� ���� ���� ���� ���¿��� � ���α׷��� ������ �����?
	// ������ �ս� ���ɼ�
	fclose(file);

	// fprintf. fscanf


}