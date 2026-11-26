
#include <vector>    // 동적배열
#include <list>      // 연결형 리스트
#include <iostream>
#include <set>

using namespace std;

int main()
{
	vector<int> vecInt;

	vecInt.push_back(1);
	vecInt.push_back(2);
	vecInt.push_back(3);
	vecInt.push_back(4);

	// list 로 치면, pop_front 를 iterator를 이용해서 수행
	vector<int>::iterator iter = vecInt.begin();
	
	int Data = *iter;

	// erase함수
	// 입력으로 iterator를 넣어주며느 iterator가 가리키는 데이터를 삭제해준다. 
	// 반환값으로, 삭제된 곳의 다음을 가리키는 iterator를 만들어서 반환해준다. 
	iter = vecInt.erase(iter); 

	// iterator가 가리키는 데이터가 제거되었으므로, iterator 객체는 더 이상 사용이 불가능하다. 
	// 따라서 erase의 반환값을 입력받아서 삭제된 다음을 가리키도록 해줘야, 다시 사용할 수 있다.
	Data = *iter; 
	// 
	//  왜 iterator로 지워지고 값이 한칸씩 땡겨지는데도 iterator를 갱신해야 사용이 가능하지?
	// iterator는 주소로 접근이 아닌가?


	// 과제 
	// 1. vector를 하나 만든다
	vector<int> vec;

	// 2. vector 안에 데이터를 1부터 100까지 채운다 (반복문)
	for (int i = 1; i <= 100; i++)
	{
		vec.push_back(i);
	}

	// 3. vector 안에 들어있는 데이터를 iterator 문법으로 순회, cout 이용, 데이터를 화면에 출력
	vector<int>::iterator veciter = vec.begin();

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec.at(i) << endl;
	}

	// 4. 반복문 돌면서 (iterator 이용) vector 안에 들어있는 데이터가 홀수면 erase로 제거
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec.at(i) % 2 == 1) {
			veciter = vec.erase(veciter);
		}
		++veciter;
	}

	cout << "홀수 데이터 제거" << endl;
	
	// 5. vector 안에 들어있는 데이터를 iterator 문법으로 순회, cout 이용, 데이터를 화면에 출력
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec.at(i) << endl;
	}




	list<int> listInt;

	listInt.push_back(1);
	listInt.push_back(2);
	listInt.push_back(3);

	listInt.pop_front();





	set<int> setInt;

	setInt.insert(1);
	setInt.insert(2);
	setInt.insert(3);

	set<int>::iterator setIter;

	setIter = setInt.begin();

	return 0;
}