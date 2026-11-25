#pragma once

// int 타입 데이터 저장

struct Node
{
	int		Data;
	Node*	pNext;
	Node*	pPrev;

	Node() : Data(0), pNext(nullptr), pPrev(nullptr) {}

	Node(int _Data) : Data(_Data), pNext(nullptr), pPrev(nullptr) {}
	
	Node(int _Data, Node* _Next, Node* _Prev) : Data(_Data), pNext(_Next), pPrev(_Prev) {}

	~Node(){}
};



class CList
{
private:
	Node*	m_Head;
	Node*	m_Tail;
	int		m_CurCount;

public:
	int size();

	// 데이터를 맨 뒤에 추가
	void push_back(int _Data);
	
	// 데이터를 맨 앞에 추가 
	void push_front(int _Data);

	// 맨 뒤에 데이터 제거
	void pop_back();

	// 맨 앞에 데이터 제거
	void pop_front();

	// 리스트 순서 뒤집기
	void reverse();

private:
	void reverse(Node* _Node);

public:
	CList();
	~CList();

};

