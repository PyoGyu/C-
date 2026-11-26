#include <vector>     
#include <iostream>

using namespace std;

int main()
{
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

	return 0;
}