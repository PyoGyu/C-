#include "CList.h"

#include <assert.h>

CList::CList()
{
	m_Head = nullptr;
	m_Tail = nullptr;
	m_CurCount = 0;
}

CList::~CList()
{
	// 헤드노드부터 출발
	Node* pNode = m_Head;

	// 모든 노드를 반복적으로 지워나간다
	while (pNode != nullptr)
	{
		Node* pTemp = pNode->pNext;
		delete pNode;
		pNode = pTemp;
	}
}

void CList::push_back(int _Data)
{
	// 동적할당으로 힙 공간에 노드 1개 들어갈 메모리 요청
	Node* pNewNode = new Node(_Data); // 데이터 저장


	// 1. 데이터가 최초 입력이라면 
	if (nullptr == m_Head)
	{
		// 데이터가 1개밖에 없다 ==> 시작과 끝
		m_Head = pNewNode;
		m_Tail = pNewNode;
	}
	// 2. 데이터를 최소 1개 이상 보유중이었다면
	else
	{
		// 기존에 마지막 노드의 뒤로 새로운 노드를 연결한다.
		m_Tail->pNext = pNewNode;
		pNewNode->pPrev = m_Tail;

		// 새로운 노드가 이제 가장 마지막 노드다. 
		m_Tail = pNewNode;
	}		
	++m_CurCount;
}

void CList::push_front(int _Data)
{
	Node* pNewNode = new Node(_Data);

	if (nullptr == m_Head)
	{
		m_Head = pNewNode;
		m_Tail = pNewNode;
	}
	else
	{
		// 새 노드의 다음 노드에 현재 헤드노드 대입
		pNewNode->pNext = m_Head;

		// 헤드 노드의 전 노드에 새 노드 대입
		m_Head->pPrev = pNewNode;

		// 세 노드를 헤드 노드로 변경
		m_Head = pNewNode;
	}

	++m_CurCount;
}

void CList::pop_back()
{	
	assert(m_Head); // 데이터가 1개 이상 보유중이었어야 한다. 

	if (m_CurCount > 1)
	{
		// 끝 노드를 한칸 뒷 노드로 수정
		m_Tail = m_Tail->pPrev;

		// 기존 끝 노드 해제 및 현재 끝 노드 다음 노드 값 초기화
		delete m_Tail->pNext;
		m_Tail->pNext = nullptr;			
	}
	else
	{
		delete m_Tail;

		m_Head = nullptr;
		m_Tail = nullptr;
	}

	// 노드 개수 갱신
	--m_CurCount;
}

void CList::pop_front()
{
	assert(m_Head); // 데이터가 1개 이상 보유중이었어야 한다. 

	//if (m_CurCount > 1)
	//{
	//	// 헤드 노드 한칸 앞으로 수정
	//	m_Head = m_Head->pNext;

	//	// 기존 헤드노드 해제 및 현재 헤드 노드 이전 노드 값 초기화
	//	delete m_Head->pPrev;
	//	m_Head->pPrev = nullptr;
	//}
	//else
	//{
	//	delete m_Head;

	//	m_Head = nullptr;
	//	m_Tail = nullptr;
	//}

	//// 노드 개수 갱신
	//--m_CurCount;

	Node* pHead = m_Head;

	m_Head = m_Head->pNext;

	if (nullptr != m_Head)
	{
		m_Head->pPrev = nullptr;
	}
	else
	{
		m_Tail = nullptr;
	}

	delete pHead;

	--m_CurCount;
}


int CList::size()
{
	return m_CurCount;
}

void CList::reverse()
{
	reverse(m_Head);
}

// 재귀함수로 구현하기
void CList::reverse(Node* _Node)
{
	///*m_head = _node->pnext;

	//if (_node->pnext != nullptr)
	//{
	//	node* temp = _node->pnext;
	//	_node->pnext = _node->pprev;
	//	_node->pprev = temp;
	//}
	//else
	//{
	//	node* temp = _node;
	//	while (temp->pprev != nullptr)
	//	{			
	//		m_tail = temp->pprev;
	//		temp = temp->pprev;			
	//	}
	//	return;
	//}

	//	reverse();*/

	if (_Node->pNext != nullptr)
	{
		reverse(_Node->pNext);
	}

	Node* temp = _Node->pNext;
	_Node->pNext = _Node->pPrev;
	_Node->pPrev = temp;

	if (_Node == m_Head)
	{
		Node* temp = m_Head;
		m_Tail = m_Head;
		m_Head = m_Tail;
	}
}
