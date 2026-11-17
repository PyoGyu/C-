
// 포인터와 구조체

// 구조체 
// 사용자 정의 자료형 (user define dataType)
struct MyType
{
	int i;
	float f;
};


int main()
{
	int i = 0;
	int* pI = &i;

	MyType t = {};
	MyType* pM = &t;

	t.f = 1.1f;
	t.i = 10;

	// 구조체 변수를 가리키는 포인터가, 목적지의 맴버에 접근할때
	(*pM).i = 20;
	(*pM).f = 2.2f;

	pM->f = 3.3f;
	pM->i = 30;

	return 0;
}

// const, const 포인터