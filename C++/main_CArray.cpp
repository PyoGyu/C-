#include "CArray.h"
#include <vector>
#include <list>

int main()
{
	CArray arr;

	arr.Push_back(10);
	arr.Push_back(20);
	arr.Push_back(30);

	int Data = arr.at(2);

	// 반환타입을 &(래퍼러스) 타입으로 반환 -> 지정한 데이터 원본을 수정 가능
	arr.at(2) = 300;


	// at 함수를 operator[] 로 대체하기
	Data = arr[1]; // ==> Data = arr.operator[](1);
	arr[1] = 100; // ==> arr.operator[](1) = 100;
	Data = arr[1];

	// STL 컨테이너 vector(동적배열) list(연결형 리스트)
	// 특징에 따라서 제동괴는 멤버함수가 다르다. 
	// vector 의 경우 push_front 가 없다. 비효율적이기 때문
	std::vector<int> vecArr;

	vecArr.push_back(10);
	vecArr.push_back(20);
	vecArr.push_back(30);
	vecArr.push_back(40);

	int value = vecArr.at(1);
	vecArr.at(1) = 100;
	value = vecArr.at(1);

	value = vecArr[1];

	// list 의 경우 인덱싱으로 접근하는 at, operator[] 멤버함수가 제공되지 않는다. 
	// 연결형 리스트는 인덱싱으로 접근하는 방법이 느리기 때문이다. 
	std::list<int> intlist;
	intlist.push_back(10);
	intlist.push_back(20);
	intlist.push_back(30);
	intlist.push_front(40);


	return 0;
}