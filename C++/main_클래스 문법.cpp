#include <stdlib.h>
// 클래스 문법
// 1. 생성자, 소멸자
//		- 클래스로 객체를 생성하거나, 객체가 소멸할때 호출이 보장되는 멤버함수
//		- 이니셜라이저 문법
//		- 생성자 오버로딩
// 2. this 포인터
//		- 클래스 전용 함수인 멤버함수 안에서, 멤버변수를 지칭하면 그앞에 생략되어 있는 포인터
//		- 멤버함수를 호출할대 호출한 객체의 주소가 입력된다.
//		- 따라서 멤버함수 안에서 멤버변수를 지칭하면, 해당 함수를 호출한 객체의 멤버를 말한다.
// 3. 연산자 오버로딩

class MyType
{
private: // 외부 공개 금지 (default가 private)
	int		a;
	float	b;

public:
	void Test()
	{
		this->a = 1;
		this->b = 2.2f;
	}

public:
	// 멤버함수 - 클래스(자료형) 전용 함수
	// 생성자 - 반환타입 명시 x, 함수 이름이 클래스 이름(자료형 이름)과 동일
	//		    객체가 생성될때 호출이 보장 됨.
	MyType()
	{
		this->a = 0;
		this->b = 1.1f;
	}
};

struct CharInfo
{
	int m_CurHP;
	int m_MaxHP;

	int m_CurMP;
	int m_MaxMP;

	int m_CurSP;
	int m_MaxSP;

	int m_Att;
	int m_Int;
	int m_Def;
	int m_Dex;
	int m_Agi;
};

class MyCharacter
{
private:
	CharInfo  m_Info;
	int*	  m_Data;

public:
	// 생성자 - 초기화(Initialize) 역할
	MyCharacter() : m_Info{}, m_Data(nullptr)
	{
		// 대입
		m_Info.m_CurHP = 100;
		m_Info.m_MaxHP = 100;

		m_Data = (int*)malloc(sizeof(int) * 100);
	}
	
	// 소멸자 - 객체가 소멸하기 직전에 호출
	//          객체가 소멸되기 직전에 해야할 마무리 작업을 수행
	~MyCharacter()
	{
		free(m_Data);
	}
};

class Test
{
private:
	int		m_i;
	float	m_f;

public:
	// 생성자 오버로딩
	// Default 생성자
	Test() : m_i(0), m_f(0.f)
	{

	}

	Test(int _i)
	{
		m_i = _i;
	}
};


class Monster
{

};


int main()
{
	MyType t;

	// 멤버함수를 이용해서 멤버변수 수정
	t.Test();

	int i = 10; // 이건 초기화
	i = 10; // 이건 대입

	// 전방선언
	// 클래스 자료형 변수명 ()-> 반환타입이 클래스타입이고, 변수명을 함수명으로 생각해서,
	// 전방선언을 했다고 해석 클래스로 기본생성자 호출하는 객체만들때는 () 붙이지 않는다. 
	Test k;

	// 생성자, 소멸자
	MyCharacter a;

	// 수동으로 직접 생성자 멤버함수 호출
	//a.MyCharacter::MyCharacter();


	// 수동으로 직접 소멸자 호출
	//a.MyCharacter::~MyCharacter();
	return 0;
}