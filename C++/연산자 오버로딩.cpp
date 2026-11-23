


class MyClass
{
private:
	int m_a;
	
public:
	// 파라미터의 타입을 MyClass 로 선언하면, MyClass 자료형 크기가 
	// 컸을 경우에는 복사비용이 크게 발생 했을 것이다. 
	// 따라서 복사비용을 줄이기 위해서 주소를 받아와야 하는데, 포인터 문법을 사용하면
	// 호출 인자 앞에 주소를 뜻하는 & 기호를 붙여아한다. 이것도 없애려면 c++ 에 추가된
	// 레퍼런스 문법을 사용하면 된다. 
	// 만약에 복사비용만 줄이고, 원본을 수정할 의도가 없을 경우에는 const &  를 사용한다. 
	MyClass operator+(const MyClass& _Other)
	{
		MyClass my;

		my.m_a = m_a + _Other.m_a;

		return my;
	}

	MyClass operator%(const MyClass& _Other)
	{
		MyClass my;

		my.m_a = m_a % _Other.m_a;

		return my;

	}

	void SetInt(int _a)
	{
		m_a = _a;
	}

public:
	MyClass() : m_a(11) {}
	~MyClass() {}
};


int main()
{
	// 연산자 오버로딩
	// 기본 자료형에 적용되던 연산자 기호를 내가만든 자료형에도 적용될 수 있도록 한다. 
	// 클래스 안에, 해당 자료형이 사용될 경우 호출될 맴버함수를 만들어둔다. operator (원하는 연산자기호)
	MyClass my1;
	MyClass my2;
	MyClass my3;
	MyClass my4;

	my1.SetInt(100);

	//my1.operator+(my2); 
	//  ㄴ원래라면 이렇게 호출하는게 정석이지만 오퍼레이터 연산자 특성상 연산자만 사용해도 알아서 됨.
	my3 = my1 + my2;
	my4 = my1 + my2 + my3;

	int i = 10;
	int i2 = 20;
	int i3 = i + i2;


	my3 = my1 % my2;


	return 0;
}