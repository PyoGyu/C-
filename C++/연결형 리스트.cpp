#include "LinkedList.h"
#include <stdio.h>

int main()
{
	LinkedList list = {};


	Push_Back(&list, 10);
	Push_Back(&list, 20);
	Push_Back(&list, 30);

	Node* pNode = list.pHead;

	for (Node* pNode = list.pHead; pNode != nullptr; pNode = pNode->pNext)
	{
		printf("Data : %d\n", pNode->Data);
	}

	return 0;
}