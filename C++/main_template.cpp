#include <vector>
#include <iostream>
#include "CArray.h"
using namespace std;


//int Add(int _a, int _b)
//{
//	return _a + _b;
//}
//
//float Add(float _a, float _b)
//{
//	return _a + _b;
//}

template<typename T>
T Add(T _a, T _b)
{
	return _a + _b;
}



int main()
{
	// 형틀
	// template - 컴파일 타임에 컴파일러가 코드를 만들어주는 기능

	int Return = Add<int>(10, 20);

	float f = Add<float>(3.423f, 4.1512f);

	CArray<int> arrInt;

	arrInt.Push_back(1);
	arrInt.Push_back(2);
	arrInt.Push_back(3);

	CArray<int>::iterator iter = arrInt.begin();

	for (; iter != arrInt.end(); ++iter)
	{
		cout << *iter << endl;
	}


	vector<int> vec;

	return 0;
}