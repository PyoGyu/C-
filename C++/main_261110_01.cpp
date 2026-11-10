// 전처리기 구문
// 주로 사용하는 구문 #include, #define, #indef
// 지정된 파일의 내용을 복사
// 기본으로 제공되는 기능, 표준입출력 관련 기능들이 정의되어있다.
#include<stdio.h>

// 빌드
// 전처리기 -> 컴파일 -> 링킹 -> 실행파일 생성

void main()
{
	// 연산자 
	// 증감
	// 산술
	// 대입

	// 비교 연산자
	// 참, 거짓
	// 1(대표 숫자), 0
	// 참 = 0이 아닌 값
	// 데이터를 참 or 거짓으로 해석한다면, 0이 아닌 모든 데이터는 참으로 본다.
	// 0은 거짓으로 본다.

	// 참 거짓 전용 자료형 bool
	// 굳이 따지면 정수타입의 자료형
	// ㄴ bool(1Byte)

	// C++ 언어로 할당할 수 있는 최소 단위는 Byte

	char c = 100;
	bool b = 100;

	c = b; // c = 1

	// bool 자료형으로 만든 변수는 참 or 거짓의 상태만 저장하기로 한다는 뜻
	// 0이 아닌 값(참) 을 저장하려고 하면, 대표 숫자인 1로 통일해서 저장


	// 비교 연산자
	// 연산자 특징에 맞는 비교를 진행 한 뒤에 결과값으로 참 or 거짓을 반환
	// ==, !=, <, >, <=, >=

	b = 10 == 10;
	// 대입 연산자는 연산자 우선순위가 가장 낮다 
	// () 안에 연산자를 사용하면 우선순위가 올라감(명시적으로도 보기 좋음)

	// 논리 연산자
	// &&(and), 두 연산자가 둘다 참인 경우에만 참을 반환
	bool IsTrue = 1 && 1;

	// ||(or), 둘중 하나만 참이여도 참 
	IsTrue = 1 || 0;

	// !(not), 반전
	IsTrue = !0;


	// 조건문 if(참 or 거짓)
	int Input = 10;
	
	bool IsSame = Input == 10;

	if (IsSame)
	{
		// "" 문자열 안에 내용을 콘솔창에 띄울 수 있음
		printf("Input Value is 10\n");
	}
	// if 조건이 실패할 경우에 추가조건 검사
	else if (Input == 12)
	{
		printf("Input Value is 12\n");
	}
	// if, else if 모두 실패했을 경우 반드시 실행되는 default 방식
	else if(Input == 15)
	{
		printf("Input Value is 15\n");
	}
	else
	{	
		printf("Input Value is unkonws\n");
	}

	// switch case 구문
	switch (Input)
	{
	case 1:

		break;
	
	case 2:

		break;
	
	default:

		break;
	}
}


