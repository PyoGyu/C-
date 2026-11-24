#include <stdlib.h>

class Monster
{
private:
	int m_att;
	int m_def;
public:
	Monster() : m_att(0), m_def(0)
	{

	}

	~Monster()
	{

	}
};



int main()
{
	//Monster* pMonster = (Monster*)malloc(8);
	Monster* pMonster = new Monster;
		
	//free(pMonster);
	delete pMonster;

	// 동작할당 및 해제에 왜 new, delete를 사용하는가 
	// C++ 에서 보장하는, 클래스 객체 생성시 생성자 호출, 객체 소멸시 소멸자 호출을 
	// 동적할당으로 힙공간에 객체를 생성할 때도 보장받으려면 이제부터 new, delete 키워드로 
	// 동적할당 및 해제를 해야한다. 
	//  ㄴ 왜 malloc은 보장 안하고 new는 보장하는가?

	Monster a;

	return 0;
}