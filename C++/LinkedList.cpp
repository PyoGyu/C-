#include "LinkedList.h"
#include <stdlib.h>


void Push_Back(LinkedList* _List, int _Data)
{
	// 데이터를 저장할 노드를 생성한다. 
	Node* pNode = (Node*)malloc(sizeof(Node));

	pNode->Data = _Data;
	pNode->pNext = nullptr;

	//  list 에 데이터가 하나도 없었다.
	if (nullptr == _List->pHead)
	{		
		// 헤드포인터가 첫번째 노드를 사리킴
		_List->pHead = pNode;

	}
	else // 보유하고 있는 마지막 데이터 노드가 이번에 생성된 노드를 가리킴
	{		
		// 지역변수로, 리스트가 보유한 첫번째 데이터를 가리키게 함
		Node* pTemp = _List->pHead;
		
		// 반복문을 돌면서 리스트가 보유한 마지막노드를 찾아냄
		while (pTemp->pNext != nullptr)
		{
			pTemp = pTemp->pNext;
		}

		// 기존에 마지막이었던 노드가, 이번 push_back 으로 생성된 노드를 가리킨다.
		pTemp->pNext = pNode;
	}

	++_List->CurCount;
}

void Push_Front(LinkedList* _List, int _Data)
{
	Node* pNode = (Node*)malloc(sizeof(Node)); // 데이터를 저장할 노드를 생성한다.

	pNode->Data = _Data; // 노드안에 데이터를 채워준다.

	Node* pTemp = _List->pHead; // temp로 데이터를 저장했는데 사실 필요 없는 행위였음 
	_List->pHead = pNode; // 리스트는 새로 생성된 노드를 맨 처음으로 가리킨다.
	pNode->pNext = pTemp; // 생성된 노드의 다음을, list의 헤드노드 주소값으로 채운다.

	++_List->CurCount; // 데이터 개수 갱신
}
