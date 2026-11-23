
#include <vector>

std::vector<int>;


void Add(int _a, int _b) 
{

}

int Add(int _a, float _b) 
{
	return 0; 
}

int Add(int _a, int _b, int _c)
{
	return 0;
}

namespace MY_SPACE
{
	int Sub(int _a, int _b)
	{
		return _a - _b;
	}

	int Gloval = 0;

	int Gloval2 = 0;
}

int Sub(int _a, int _b)
{
	return _a - _b;
}

int Gloval = 0;


// 네임스페이스 제거 (네임스페이스를 안써도 되도록 편의를 봐줌)
//  ㄴ 이 이후부터는 std 네임스페이스 안에 있는 기능에 접근할때 std:: 를 붙이지 않아도 된다.
using namespace std;
//using namespace MY_SPACE;

// 특정 namespace 안에 있는 기능중에 지정한것만 앞에 namespace 붙이지 않아도 되도록 함
using MY_SPACE::Gloval2;



int main()
{

	// namespace
	// 범위지점 연산자 -> :: (스코프라 읽음)
	// 특정 namespace 안에 있는 기능을 언급 가능
	// 같은 이름의 함수, 정의, 변수 등등을 허용하게 하기 위해서, 
	// namespace 가 다르면 완벽하게 같은 함수명 or 변수명 이어도 정의가 가능하다, 구별할 여지가 생기기 때문
	MY_SPACE::Sub(10, 5);
	Sub(20, 10);

	MY_SPACE::Gloval = 100;

	Gloval = 200;

	Gloval2 = 20;

	vector<int>;


	// 열거형
	enum PLAYER_STATE // 플레이어의 상태종류 (signed int)
	{
		IDLE,	// 0
		MOVE,	// 1
		RUN,	// 2
		DASH,	// 3
		ATTACK, // 4
		HEART,	// 5
		DEAD,	// 6
	};
	// ui 상태를 나타낼때도 많이 사용함 (마우스가 창 위에 있는지, 창이 커져 있는지 등)
	
	// enum (열거형), int
	PLAYER_STATE state = IDLE;

	state = DASH;
	// (PLAYER_STATE)3 이렇게 강제 형변환을 하는게 아니면 , 
	// 열거형을 벗어난 정수나 0, 3 같은 범위에 해당 하는 정수도 대입 불가하다
	// 문법상에서 오류 방지를 위해 막아둠


	// 래퍼런스 vs 포인터
	// c++으로 넘어오면서 만들어진 문법 래퍼런스
	int i = 0;
	int i2 = 0;

	int* pInt = &i;
	*pInt = 100; 

	pInt = &i2;
	*pInt = 100; // i2 가 수정됨

	// 변수명 앞에 주소기호를 붙이고,
	// 포인터 앞에 *(역참조, 접근) 연산자를 붙이는 수고를 줄이기 위해
	// 래퍼런스라는 새로운 문법을 추가
	// 어셈블리 코드상으론 사실상 동일, c++ 코드 작성 기준으로는 좀 더 편리해짐
	int& ref = i;
	ref = 200;
	
	// 참조 대상을 바꾸는 것이 아니라, 처음 참조한 대상인 i 에 i2 의 값을 넣겠다는 뜻이 됨.
	// 래퍼런스는 처음 선언시에만 참조 대상을 설정할 수 있음.
	ref = i2;

	// 차이점 포인터의 경우 역참조 연산을 통해 원본을 수정하지만 래퍼런스는 변수를 통해 바로 접근이 가능하고,
	// 저장할때도 주소 키워드가 필요가 없음

	// 참조나 포인터나 기계어로(어셈블리) 변환 했을때 완전 동일함


	// 클래스


	return 0;
}