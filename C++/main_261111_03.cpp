#include <stdio.h>

// 함수 선언방법
// 반환타입(반환되는 데이터의 자료형)
// 함수 이름
// 함수 입력인자 타입

// 함수를 사용하는 이유
// 자주사용하는 패턴, 기능 단위를 모듈(부품)화 함.
// 반복적인 코드 복사를 줄이고 재활용 하도록 함
// 코드의 모듈화

// 기능 - 입력인자로 행을 넣어주면 해당 횟수만큼 * 을 출력해줌
void OutputStart(int _Row)
{
	for (int i = 0; i < _Row; ++i)
	{
		for (int j = 0; j < _Row - i; ++j)
		{
			printf("*");
		}

		printf("\n");
	}
}

// 더하기 함수
int AddFunc(int _a, int _b)
{
	return _a + _b;
}

void main()
{
	// 함수(Function)

	OutputStart(4);
	
	// 디버깅할때 f10 은 프로시저 단위
	//           f11 은 최소 명령단위로 실행
	int Value = AddFunc(20, 50);

}

