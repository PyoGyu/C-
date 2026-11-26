#include "CArray.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	CArray myArr;

	myArr.Push_back(1);
	myArr.Push_back(2);
	myArr.Push_back(3);

	/*CArray::iterator it1 = myArr.begin();
	CArray::iterator it2 = myArr.end();

	it1 != it2;*/

	//int Data = it.operator*(); // = *it;

	CArray::iterator iter = myArr.begin();

	for (; iter != myArr.end(); ++iter)
	{
		cout << *iter << endl;
	}

	iter = myArr.begin();
	iter = myArr.erase(iter);

	for (; iter != myArr.end(); ++iter)
	{
		cout << *iter << endl;
	}

	return 0;
}