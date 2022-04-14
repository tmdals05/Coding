#include <stdio.h>

#define MAX 10000

int main()
{
	// 파일 입출력
	// 파일에 어떤 데이터를 저장
	// 파일에 저장된 데이터를 불러오기

	// fputs, fgets
	char line[MAX];  // char line[10000]
	FILE* file = fopen("F:\\test1.txt", "wb"); // r(읽기 전용), w(쓰기 전용), a(이어쓰기), t(텍스트), b(바이너리 데이터)

	if (file == NULL)
	{
		printf("파일 열기 실패\n");
		return 0;
	}
	
	fputs("fputs를 이용해서 글을 적어볼게요\n", file);
	fputs("잘 적히는지 확인해주세요\n", file);

	// 파일을 열고 나서 닫지 않은 상태에서 어떤 프로그램에 문제가 생기면?
	// 데이터 손실 가능성
	fclose(file);

	// fprintf. fscanf


}