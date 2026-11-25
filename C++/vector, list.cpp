#include <vector>
#include <list>
#include <iostream>

using namespace std;

void vector_Clear(vector<int>& _vec)
{
	vector<int> tempVec;

	_vec.swap(tempVec);
}



int main()
{
	vector<int> vecInt;

	vecInt.reserve(10);

	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);
	vecInt.push_back(40);
	vecInt.push_back(50);

	int value = vecInt.size();
	value = vecInt.capacity();

	vector<int> vecInt2;

	// clear 함수는 개념적으로만 데이터를 제거, size값만 0으로 변경, capacity 는 여전히 존재함.
	// 함수안레 지역변수 vector랑 데이터를  교환
	vecInt.swap(vecInt2);
	
	// clear 함수는 size만 초기화하고 기존에 데이터는 아직남아있음 
	vector_Clear(vecInt);

	// 디자인 패턴 - 프로그래밍을 할때 자주 발생하는 설계를 유형(패턴)으로 정리
	// iterator 패턴, 컨테이너 안에 있는 데이터를 가리키는 iterator 를 같이 제공

	for (int i = 0; i < 100; i++)
	{
		vecInt.push_back(i + 1);
	}
	vector<int>::iterator iter = vecInt.begin();

	int data = *iter;

	data = *(iter + 1);

	++iter;

	data = *iter;

	*iter = 10;

	// iterator 기능을 이용해서 vector 안에 저장해둔 데이터를 모두 순회해서 출력
	vector<int>::iterator veciter = vecInt.begin();
	for (; veciter != vecInt.end(); ++veciter)
	{
		std::cout << *veciter << endl;
	}

	// vectpor 의 경우 메모리가 연속적인 공간안에 저장하기 때문에, 인덱스로 바로 접근이 가능하다. 
	// 따라서 iterator 기능 없이도, 저장한 데이터를 처음부터 끝까지 순회가 가능
	for (int i = 0; i < vecInt.size(); i++)
	{
		cout << vecInt.at(i) << endl;
		//cout << vecInt[i] << endl;
	}



	list<int> listInt;

	for (int i = 0; i < 5; i++)
	{
		listInt.push_back(i + 1);
	}

	// list 는 데이터가 띄엄띄엄 노드단위호 끊어져서 주소로 연결되어있는 구조이기 때문에, 
	// 컨테이너 차원에서 특정 인덱스에 해당하는 데이터에 접슨하는 기능을 제공하지 않는다. 
	// 따라서 iterator 를 이용해서 내부요소를 가르켜 가면서 저장된 전체 데이터를 순회해야 한다. 

	list<int>::iterator listiter = listInt.begin();
	for (; listiter != listInt.end(); ++listiter)
	{
		std::cout << *listiter << endl;
	}


	return 0;
}