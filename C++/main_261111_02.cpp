#include <stdio.h>
#include <random>
#include <time.h>

// 반복문 응용

void main()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < i+1; ++j)
		{
			printf("*");
		}

		printf("\n");
	}

	for (int i = 5; i > 0; --i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			printf("*");
		}
		
		printf("\n");
	}

	/*int count = 5;
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count-i; ++j)
		{
			printf("*");
		}

		printf("\n");
	}*/


	// 배열 Array
	// 특정 자료형으로 변수를 여러개 선언하고 싶을때
	// 배열은 선언 시 쓰레기 데이터가 들어가 있는것을 방지하기 위해서 초기화를 해주는것이 좋음
	// 처음에 원하는 값을 각 칸에 초기값으로 넣어줄 수도 있음
	int MyArray[10] = {};
	MyArray[0] = 1; // 배열의 첫번째에 1을 대입
	MyArray[1] = 2; // 배열의 두번째에 2을 대입
	MyArray[2] = 3; // ..

	// n 개 선언시, n 인덱스부터 존재하지 않는다.
	MyArray[19]; // 내가 만든 배열의 크기를 벗어남
	// 오프셋 : 특정 기준으로 부터 얼마나 떨어졌는지


	// 반복문을 이용해서 배열의 초기값을 세팅하시오
	// 100개의 배열 요소를 1 부터 100까지 채우기
	int Test[100] = {};

	for (int i = 0; i < 100; ++i)
	{
		Test[i] = i + 1;
	}

	// 역순
	for (int i = 0; i < 100; ++i)
	{
		Test[i] = 100 - i;
	}
	// 짝순
	for (int i = 0; i < 100; ++i)
	{
		Test[i] = (i+1) * 2;

	}
	// 홀수
	for (int i = 0; i < 100; ++i)
	{
		Test[i] = i * 2 + 1;
	}



	// 랜덤값 만들기 

	// 햔재 시간
	time_t t = time(0);
	// time_t도 그냥 longlong 변수를 가시성을 높이기 위해 tyedef한거다.

	// 난수 페이지 섞기
	srand(t); 
	
	// 난수를 추출
	int a = rand();
	int b = rand();

	// 1 ~ 100 사이의 랜덤 숫자 얻기
	//(rand() % 100) + 1;

	// 배열을 랜덤값으로 채우기
	for (int i = 0; i < 100; ++i)
	{
		Test[i] = (rand() % 1000) + 1;
	}

	// 랜덤한 배열 요소중에서 최대 or 최소 찾아내기
	int MaxValue = 0;
	int MinValue = 1000 ;
	for (int i = 0; i < 100; ++i)
	{
		if (Test[i] > MaxValue)
			MaxValue = Test[i];

		if (Test[i] < MinValue)
			MinValue = Test[i];
	}

	printf("MaxValue : %d\n", MaxValue);
	printf("MinValue : %d\n", MinValue);

	char c = '1';

	// char(1바이트, 정수, 문자) 배열 
	char Number[10] = {};

	Number[0] = 50;
	Number[1] = 51;
	Number[2] = 52;

	// 배열의 특징 
	// 1. 연속된 메모리 공간에 생성
	// 2. 배열의 이름자체가 시작 주소

}