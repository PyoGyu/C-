#include <Windows.h>
// 전처리기
// 매크로
#define SOME 10
#define ANJANAFE_GREATESWORD 213
// 매크로 함수
#define ADD(a, b)	a + b

// 가독성
// 특정 수치를 문자형태로 관리할 수 있고,
// 유지보수의 편의성이 높고
// 특정 의도를 가진 구치를 일괄 관리가능

#define BURNING		1    //0000 0001    // 0x1
#define ElECTRIC	2    //0000 0010    // 0x2
#define POISION		4    //0000 0100    // 0x4
#define Cold		8    //0000 1000    // 0x8
#define BLEED		16   //0001 0000    // 0x10
#define BLIND       32   //0010 0000    // 0x20

// 매크로 조합을 만들어 새 매크로를 만들 수 있음 세개를 한번에 적용 가능 
#define WARLOCK_SPECIAL (BURNING | ElECTRIC  | BLIND) // 0010 0011


// 0x 가 붙으면 16진법 표기법
//16 진법으로 1, 2, 4, 8 이 반복되면, 2진법기준 특정 자리 비트에 해당하는 숫자들
//0x01
//0x02
//0x04
//0x08
//0x10
//0x20
//0x40
//0x80

void main()
{
	int Data = SOME;

	Data = ADD(2, 3);

	int WeaponEquip = ANJANAFE_GREATESWORD; //213


	// 비트 연산자 _정수에만 사용가능
	// 비트단위로 연산을 진행시키는 연산자
	// & (비트 And)
	// 논리 And 연산을 비트단위로 진행, 각자리 비트가 둘다 1인경우에만 1을 반환
	Data = 10 & 15; // 1 0 1 0 -> 10

	// | (비트 or)
	// 논리 or 연산을 비트단위로 진행, 둘중 하나만 1이어도 1을 반환
	// 1 0 1 0
	// 1 1 1 1
	// 1 1 1 1 -> 15
	Data = 10 | 15; 

	// ^ (비트 xor)
	// 같으면 0, 다르면 1을 반환
	// 1 0 1 0
	// 1 1 1 1
	// 0 1 0 1 -> 5
	Data = 10 ^ 15;


	// ~ (비트 Not, 반전) -> ! 연산자의 비트 버전이라 생각
	// 비트단위로, 각 자리 비트를 반전시킨다.
	unsigned char c = 0;
	c = ~c; // 255
	c = ~c; // 0

	// 비트 쉬프트
	// >>, <<
	// 왼쪽으로 이동시, 모든 비트 자리가 1칸씩 이동할때마다 전체값이 2배씩 증가
	// 4칸 이동시 2^4(16) 배 증가
	// 오른쪽으로 1칸 마다 2로 나눈 몫
	Data = 5;
	Data <<= 1;
	Data <<= 2;

	Data >>= 1;
	Data >>= 1;

	// 1111 1000 -> -8
	// 1022 1100 -> -4
	char sc = -8;
	sc >>= 1;

	// 1111 1111 -> 257
	// 0111 1111 -> 127
	c = 255;
	c >>= 1;

	// 음수의 경우, 비트 쉬프트를 진행할때 MSB(부호판변 비트, 가장 앞자리 비트)는 훼손되지 않도록 한다.
	// 2의 곱셈, 나눗셈 연산에서 부호가 변경되는 현상 방지

	// unsigned 로 선언된 양수만 표현하는 변수의 경우, MSB 를 신경쓰지 않는다.



	// 비트연산자 어디에다가 쓸까?
	// ㄴ 전처리기랑 엮어서 사용하는 경우가 많음

	// 상태값 조합할때 가장 많이 사용함
	// BURNING
	// ELECTRIC
	// COLD
	// POISION

	bool IsBurn = false;
	bool IsElectric = false;
	bool IsCold = false;
	bool IsPoision = false;

	int PlayerStatus = 0;

	// 상태 추가(지정된 비트 자리에 값 추가)
	PlayerStatus |= BURNING;
	PlayerStatus |= ElECTRIC;

	// 상태이상 여부가 궁금하면
	// 해당 상태 비트자리에 값이 있는지 확인
	if (PlayerStatus & ElECTRIC)
	{
		
	}

	// 특정 비트자리를 비우기
	PlayerStatus &= ~BURNING; // 화상 여부와 상관없이 무조건 비움

	// Burning 상태가 있는지 확인하고 제거 
	// xor을 사용하면 
	if(PlayerStatus & BURNING)
	{
		// 화상이 아닌 상태면 화상이 생김 그래서 조건이 필요 
		// 체크박스 같은 것을 구현하기에는 ^ (xor)이 적함하다. 조건없이 사용가능
		PlayerStatus ^= BURNING; 
	}

	// 자주 사용하는 상태를 미리 조합해둔 매크로로, 한번에 상태를 여러개 추가
	PlayerStatus |= WARLOCK_SPECIAL;
}


// 음수를 2진수로 나타냈을때 같은 크기의 양수를 더해 0000 0000으로 되도록 나온다.
// 1111 1000 -> -8
// 0000 1000 -> 8
// 0000 0000 -> 0