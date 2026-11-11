#include <stdio.h>


// 매크로와 typedef 차이

#define BURNING 1
#define LL long long
#define I64 __int64


typedef unsigned char BYTE;

// 전처리기는 컴파일 이전단계에서 동작하기 때문에, 매크로로 정의한 이름정보는 존재하지 않는다.
// typdef 으로 재정의한 내용은 C++ 문법에 해당하기 때문에, 컴파일러가 정보를 수집한다.


void main()
{
	// 삼항 연산자
	int Input = 10;

	if (Input == 10)
		printf("10\n");	
	else	
		printf("Input is not 10\n");
	
	// 조건 ? 참일때 실행문 : 거짓일때 실행문
	Input == 10 ? printf("10\n") : printf("Input is not 10\n");


	LL a;
	BYTE c;


	//반복문
	//while, do whlie, for
	int i = 0;
	while (i < 10)
	{
		// 실행문

		++i;
	}

	do
	{
		// 실행문

		++i;
	}
	while (i < 10);

	// for (초기화 구문; 참or 거짓; 반복문 1회마다 후속으로 실행)
	for (int i; i< 10; ++i)
	{

	}



}


// 타입 재정의, 반복문, 삼항연사자, 배열, 랜덤, 함수