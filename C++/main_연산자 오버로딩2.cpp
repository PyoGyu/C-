#include <stdio.h>
#include <iostream>

namespace My
{
	int global = 0;
}

namespace My
{
	int global2 = 0;
}

//using namespace std;
using std::cout;
using std::endl;


// 연산자 오버로딩
class MyOStream
{
private:
	unsigned int m_UseCount; // 사용횟수

public:
	MyOStream& operator<< (int _Number) // 반환 타입에 찹조를 붙여야 함수를 호출한 호출자가 그대로 리턴됨. 
	{
		++this->m_UseCount;

		printf("%d", _Number); 

		return *this;
	}

	MyOStream& operator<< (const char* _String)
	{
		++m_UseCount;

		printf("%s", _String);

		return *this;
	}

	MyOStream& operator<< (void (*_FuncPoiunter)(void))
	{
		_FuncPoiunter();

		return *this;
	}

public:
	MyOStream() : m_UseCount(0) {}
	~MyOStream() {}

};

// 클래스를 선언하는데 아무 데이터가 안들어가 있으면 0바이트가 잡히는데,
//메모리는 0 바이트를 잡을 수 없기 때문에 최소 단위로 1바이트가 잡힌다. 물론 이런식으로 사용할 일은 없음

MyOStream MyCout;

int Test()
{
	int a = 0;

	return a;
}

int AAA()
{
	return 0;
}

void MyEndL()
{
	printf("\n");
}

int main()
{
	//printf("올해 제 나이는 %d 입니다.\n", 19);

	//cout << "올해 제 나이는" << 19 << " 입니다." << endl;

	//MyCout.operator<<(10); // => MyCout << 10; 랑 같음

	MyCout << "올해 제 나이는 " << 19 << " 입니다.";

	MyCout << MyEndL;

	// 함수 포인터, 특정 코드의 주소값
	// 함수 포인터는 선언시에 설정한 구조에 맞는 함수의 주소만 받을 수 있다. 
	int(*pFunc)(void) = &Test;;
	pFunc();

	pFunc = &AAA;
	pFunc();

	return 0;
}