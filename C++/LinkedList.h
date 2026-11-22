#pragma once


// 연결형 리스트 
// 데이터마다 각각 별도의 노드에 데이터를 저장하고, 데이터 끼리 서로를 연결함
// 리스트 컨테이너 본체는 첫번째 데이터의 주소만 알고 있음

// 데이터를 중간에 삽입하거나 , 삭제할때 효율성을 보임
// 반면에 동적배열과 달리 인덱스를 이용해서 특정 순번에 데이터에 접근할때 최악의 경우
// N(데이터 개수)번 접근해야 할 수 있음 

// 알고리즘 효율		
//						데이터 삽입, 삭제		인덱싱			탐색
//	동적배열				   O(N)					O(1)			O(N), 순차탐색
//	연결형 리스트		   O(1)					O(N)			O(N), 순차탐색
//	이진탐색트리													O(logN), 이진탐색
//	해시테이블													O(1)

struct Node
{
	int Data;
	Node* pNext;
};

struct LinkedList
{
	Node*	pHead;
	int		CurCount;
};

// 데이터를 맨 뒤에 넣는다.
void Push_Back(LinkedList* _List, int _Data);

// 데이터를 맨 앞에 넣는다.
void Push_Front(LinkedList* _List, int _Data);