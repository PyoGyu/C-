#pragma once

// int 자징 베얄

class CArray
{
private:
	int*	m_Data;
	int		m_CurCount;
	int		m_MaxCount;

public:
	void Push_back(int _Data);
	void Reserve(int _Count);
	int& at(int _Idx); // 반환 타입을 int* 로도 가능
	int& operator[](int _Idx);

public:
	CArray() : m_Data(nullptr), m_CurCount(0), m_MaxCount(0)
	{

	}

	~CArray()
	{
		if (nullptr != m_Data)
			delete(m_Data);
	}

};

