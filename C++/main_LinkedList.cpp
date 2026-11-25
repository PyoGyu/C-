#include "CList.h"

void Test(int& _pointer)
{
	_pointer = 100;
}


int main()
{
	int a = 0;

	Test(a);


	// int 타입 데이터를 저장하는 CList 

	CList mylist;
	mylist.push_front(10);
	mylist.push_front(20);
	mylist.push_front(30);
	mylist.push_front(40);

	int Count = mylist.size();

	if (Count != 0)
	{
		mylist.pop_back();
	}

	return 0;
}